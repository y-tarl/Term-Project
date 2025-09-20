import cv2
import numpy as np
import time
import queue
from threading import Event
import sys
from Transbot_Lib import Transbot

# 创建Transbot对象 bot
bot = Transbot()

# 启动接收数据 
bot.create_receive_threading()

def curl_arm():
    bot.set_uart_servo_angle(7, 215)
    time.sleep(0.1)
    bot.set_uart_servo_angle(8, 30)
    time.sleep(0.3)

# 伸直机械臂
def straight_arm():
    bot.set_uart_servo_angle(8, 200)
    time.sleep(0.1)
    bot.set_uart_servo_angle(7, 70)
    time.sleep(0.3)

# 放松机械臂
def release_arm():
    bot.set_uart_servo_angle(9, 40)  
    time.sleep(0.3)

# 加紧机械臂
def tight_arm():
    bot.set_uart_servo_angle(9, 118)  
    time.sleep(0.3)


class RoadDetect():
    def __init__(self):
        self.k = -1
        self.b = 120
        self.nwindows = 10
        self.minpix = 20
        self.margin = 25
        self.frame = None
        self.road_flag = -1
        self.cross_flag = 0

        self.y_d = 0.5
        self.y_u = 1
        self.x_d = 0.5
        self.x_u = 1
        self.lower_color = np.array([60, 80, 15])
        self.upper_color = np.array([90, 231, 240])

    # 计算斜率
    def cal_k(self):
        if self.center1[0] - self.center2[0] != 0 and self.center1[1] - self.center2[1] != 0:
            self.k = (self.center1[1] - self.center2[1]) / (self.center1[0] - self.center2[0])
        else:
            self.k = 0
        pass

    # 计算截距
    def cal_b(self):
        if self.k == 0:
            self.b = self.center1[0]
        else:
            self.b = self.center1[1] - self.k * self.center1[0]
        pass

    def road_filter(self):
        # 做二值图下半部分的直方图
        histogram = np.sum(self.op_bin[(self.op_bin.shape[0] // 3) * 2:, :], axis=0)
        # 做输出图像的背板
        self.b_out_img = np.zeros_like(self.op_bin)
        # 取直方图中值最大的坐标，作为滑动窗口展开的基准
        base = np.argmax(histogram)
        # 计算每个窗口的高度
        window_height = np.int_(self.op_bin.shape[0] / self.nwindows)
        # 取出二值图中所有白点的坐标
        nonzero = self.op_bin.nonzero()
        nonzeroy = np.array(nonzero[0])
        nonzerox = np.array(nonzero[1])
        # 存储所有属于道路的白点的索引
        lane_inds = []
        for window in range(self.nwindows):
            # 确定本轮循环滑动窗口的位置
            win_y_low = self.op_bin.shape[0] - (window + 1) * window_height
            win_y_high = self.op_bin.shape[0] - window * window_height

            win_x_left = base - self.margin
            win_x_right = base + self.margin
            # 画出滑动窗口
            cv2.rectangle(self.b_out_img, (win_x_left, win_y_low), (win_x_right, win_y_high), (255, 255, 255), 2)
            # 提取所有在滑动窗口内的白点的索引
            good_inds = ((nonzeroy >= win_y_low) & (nonzeroy < win_y_high) & (nonzerox >= win_x_left) & (
                    nonzerox < win_x_right)).nonzero()[0]
            # 添加进道路白点索引
            lane_inds.append(good_inds)
            # 如果窗口内有一定的白点，则更新下一轮滑动窗口展开的基准，更新的数值为本次滑动窗口内所有白点的横坐标的中值
            if len(good_inds) > self.minpix:
                base = np.int_(np.mean(nonzerox[good_inds])) + 18 * self.road_flag
            else:
                base = base + 18 * self.road_flag

        # 将所有属于道路的白点的索引整理成一维的
        lane_inds = np.concatenate(lane_inds)
        # 取出所有属于道路的白点的坐标
        lanex = nonzerox[lane_inds]
        laney = nonzeroy[lane_inds]
        self.b_out_img[laney, lanex] = 255
        cv2.imshow('binary', self.b_out_img)

    def cross_detect(self, fenmu, fenzi, lower_color, upper_color):
        w = self.frame.shape[1]
        h = self.frame.shape[0]
        self.cropped_hsv = self.frame[int(h // 3 * 2):h, (w//fenmu)*fenzi:(w//fenmu)*fenzi + 1]

        self.cropped_hsv = cv2.cvtColor(self.cropped_hsv, cv2.COLOR_BGR2HSV)

        self.color_mask = cv2.inRange(self.cropped_hsv, lower_color, upper_color)
        white_pixel_coordinates = cv2.findNonZero(self.color_mask)

        if white_pixel_coordinates is not None:
            color_y = np.max(white_pixel_coordinates[:, 0, 1])
            cv2.circle(self.frame, ((w // fenmu) * fenzi, color_y + h//2), 2, (0, 255, 0), -1)
            return color_y + int(h//3 * 2)
        else:
            return 0


    # 图像处理过程
    def process(self):
        # 裁剪图像
        self.cropped_frame = self.frame[int(self.y_d * self.frame.shape[0]):np.int(self.y_u * self.frame.shape[0]),
                             int(self.x_d * self.frame.shape[1]):np.int(self.x_u * self.frame.shape[1])]

        # 灰度化
        self.gray = cv2.cvtColor(self.cropped_frame, cv2.COLOR_BGR2GRAY)

        # 二值化
        _, self.binary = cv2.threshold(self.gray, 80, 255, cv2.THRESH_BINARY)

        # 颜色反转
        self.binary = cv2.bitwise_not(self.binary)

        kernel = np.ones((3, 3), np.uint8)
        self.op_bin = cv2.morphologyEx(self.binary, cv2.MORPH_OPEN, kernel)


        cv2.imshow("123", self.op_bin)
        if cv2.waitKey(1) & 0xFF == ord('q'):
            exit()

        # 过滤出道路
        self.road_filter()

        # 检测轮廓
        _, self.contours, self.hierarchy = cv2.findContours(self.b_out_img, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

        # 第一靠下和第二靠下的轮廓的索引
        self.con1_index = -1
        self.con2_index = -1

        # 第一靠下的轮廓和第二靠下的轮廓中心点的y值和x值
        self.y1 = -1
        self.x1 = -1
        self.y2 = -1
        self.x2 = -1

        # 轮廓的索引和外接矩形列表
        con_list = []
        max_area = 0
        max_area_index = 0
        # 找出第一靠下和第二靠下的轮廓，并记录其圆心坐标和索引
        if len(self.contours) != 0:
            # 遍历所有轮廓
            for index, con in enumerate(self.contours):
                # 对轮廓进行简单的过滤，面积大于20的轮廓添加进列表
                area = cv2.contourArea(con)
                if area > max_area:
                    max_area = area
                    max_area_index = index

            r_x, r_y, w, h = cv2.boundingRect(self.contours[max_area_index])
            con_list.append([max_area_index, r_y + h, r_x, r_x + w, r_y])

            # 记录下矩形四个角的坐标(x,y)
            self.left_down = [con_list[0][2] + int((120 - (con_list[0][1] - con_list[0][4])) * (5 / 110)), con_list[0][1]]
            self.right_up = [con_list[0][3] - int((120 - (con_list[0][1] - con_list[0][4])) * (5 / 110)), con_list[0][4]]

            self.left_up = [con_list[0][2] + int((120 - (con_list[0][1] - con_list[0][4])) * (5 / 110)), con_list[0][4]]
            self.right_down = [con_list[0][3] - int((120 - (con_list[0][1] - con_list[0][4])) * (5 / 110)), con_list[0][1]]

            # 记录下外接圆的圆心
            (x, y), radius = cv2.minEnclosingCircle(self.contours[con_list[0][0]])
            self.y1 = y
            self.x1 = x
            self.center1 = (int(x), int(y))
            # 记录下轮廓的索引
            self.con1_index = con_list[0][0]
            # 更新标记
            self.flag = 1
            
        cnt = 0
        y6 = self.cross_detect(20, 6, self.lower_color, self.upper_color)
        if y6 > 230:
            cnt += 1
        y7 = self.cross_detect(20, 7, self.lower_color, self.upper_color)
        if y7 > 230:
            cnt += 1
        y8 = self.cross_detect(20, 8, self.lower_color, self.upper_color)
        if y8 > 230:
            cnt += 1
        y9 = self.cross_detect(20, 9, self.lower_color, self.upper_color)
        if y9 > 230:
            cnt += 1
        y10 = self.cross_detect(20, 10, self.lower_color, self.upper_color)
        if y10 > 230:
            cnt += 1
        y11 = self.cross_detect(20, 11, self.lower_color, self.upper_color)
        if y11 > 230:
            cnt += 1
        y12 = self.cross_detect(20, 12, self.lower_color, self.upper_color)
        if y12 > 230:
            cnt += 1
        y13 = self.cross_detect(20, 13, self.lower_color, self.upper_color)
        if y13 > 230:
            cnt += 1
        y14 = self.cross_detect(20, 14, self.lower_color, self.upper_color)
        if y14 > 230:
            cnt += 1
        if cnt >= 5:
            self.cross_flag = 1
        self.cal_data()

    def cal_data(self):
        if self.left_up[0] - self.right_down[0] != 0 and self.left_up[1] - self.right_down[1] != 0:
            self.k = (self.left_up[1] - self.right_down[1]) / (self.left_up[0] - self.right_down[0])
        else:
            self.k = 1
        self.b = self.left_up[1] - self.k * self.left_up[0]
        self.x = int((70 - self.b) / self.k)
        if self.road_flag * self.k > 0:
            self.x = -self.x
        pass

Road = RoadDetect()
desired_width = 320
desired_height = 240
desired_fps = 120

if __name__ == '__main__':
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, desired_width)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, desired_height)
    cap.set(cv2.CAP_PROP_FPS, desired_fps)

    prev_time = time.time()
    frame_count = 0
    cap_cnt = 0
    release_arm()
    time.sleep(0.5)
    curl_arm()
    time.sleep(1.5)


    while True:
        ret, Road.frame = cap.read()
        if not ret:
            print("没有图像")
            continue

        frame_count += 1
        current_time = time.time()
        elapsed_time = current_time - prev_time

        if elapsed_time > 1.0:
            fps = frame_count / elapsed_time
            frame_count = 0
            prev_time = current_time
            print(f"FPS: {fps:.2f}")

        if Road.frame.shape[:2] != (desired_height, desired_width):
            print(resize)
            Road.frame = cv2.resize(Road.frame, (desired_width, desired_height))

        if cap_cnt < 5:
            cap_cnt += 1
            continue

        Road.process()
    
        
        if Road.x - 90 > 0:
            x_speed = min((Road.x - 90) * 0.004, 0.3)
        else:
            x_speed = max(-0.3, (Road.x - 90) * 0.004)
        print(f"Road.x: {Road.x}, x_speed: {x_speed}")

        if Road.cross_flag == 1:
            bot.set_car_motion(0, 0)
            time.sleep(2)
            straight_arm()
            time.sleep(0.5)
            tight_arm()
            time.sleep(3)
            curl_arm()
            break
        else:
            bot.set_car_motion(0.2, -x_speed)
            pass

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    bot.set_car_motion(0, 0)
    del bot
    cap.release()
    cv2.destroyAllWindows()
