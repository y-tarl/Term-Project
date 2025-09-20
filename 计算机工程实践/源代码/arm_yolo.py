#!/usr/bin/env python3
# coding=utf-8
import time
import cv2
from Transbot_Lib import Transbot
import inferapi
import threading
import queue

# 初始化YOLO模型
YOLO = inferapi.ExternalInference('best.pt', 320)

# 打开摄像头
cap = cv2.VideoCapture(0)
if not cap.isOpened():
    print("Error: Cannot open video stream or file")
    exit()

# 计算FPS相关变量
prev_time = 0
fps = 0
start_arm = False
arm_flag = 0
mid_y = 0
mid_x = 0
cnt = 0
# 创建Transbot对象 bot
# Create Transbot object as bot
bot = Transbot()

# 启动接收数据
# Start receiving data
bot.create_receive_threading()


# 弯曲机械臂，抓取前的状态
def curl_arm():
    bot.set_uart_servo_angle(7, 215)
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
    bot.set_uart_servo_angle(9, 30)
    time.sleep(0.3)


# 加紧机械臂
def tight_arm():
    bot.set_uart_servo_angle(9, 125)
    time.sleep(0.3)


find_green = False
certain_green = False


def image_capture_thread(framequeue):
    while True:
        ret, frame = cap.read()
        if not ret:
            break
        if framequeue.qsize() < 2:
            framequeue.put(frame)
        time.sleep(0.005)

def get_image_time(stop_time):
    st_time = time.time()
    while time.time() - st_time < stop_time:
        if not framequeue.empty():
            frame = framequeue.get()
            cv2.imshow('image', frame)
        time.sleep(0.005)

if __name__ == '__main__':
    curl_arm()
    time.sleep(0.2)
    release_arm()
    time.sleep(0.2)

    framequeue = queue.Queue(maxsize=3)
    capture_thread = threading.Thread(target=image_capture_thread, args=(framequeue,))
    capture_thread.daemon = True
    capture_thread.start()

    while True:
        if not framequeue.empty():
            frame = framequeue.get()
            if cnt < 5:
                cnt += 1
                # 显示结果图像
                cv2.imshow('image', frame)
                continue

            # 推理
            detected_info = YOLO.infer(frame)

            # 找出置信度大于0.5且面积最大的目标
            max_area = 0
            best_info = None
            for info in detected_info:
                bbox = info['bbox']
                confidence = info['confidence']
                if confidence < 0.75:
                    continue
                area = (bbox[2] - bbox[0]) * (bbox[3] - bbox[1])
                if area > max_area:
                    max_area = area
                    best_info = info

            # 画出检测到的目标
            if best_info is not None:
                bbox = best_info['bbox']
                confidence = best_info['confidence']
                cls = best_info['class']
                label = f'{cls} {confidence:.2f}'
                color = (0, 255, 0)
                cv2.rectangle(frame, (bbox[0], bbox[1]), (bbox[2], bbox[3]), color, 2)
                cv2.putText(frame, label, (bbox[0], bbox[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
                print((bbox[0], bbox[1]), (bbox[2], bbox[3]), (bbox[2] - bbox[0]) * ((bbox[3] - bbox[1])))
                mid_x = int((bbox[0] + bbox[2]) / 2)
                mid_y = int((bbox[1] + bbox[3]) / 2)
                if cls == 'green':
                    find_green = True
            else:
                find_green = False

            if find_green == True and max_area > 11500 and not certain_green:
                certain_green = True

            if find_green and not certain_green:
                x_speed = 0
                x_speed = abs(mid_x - 320) * 0.0018
                if mid_x - 320 > 0:
                    x_speed = -x_speed
                    
                bot.set_car_motion(0.10, x_speed)
            elif certain_green:
                x_ready = False
                y_ready = False
                while True:
                    if framequeue.empty():
                        print("没有图像")
                        time.sleep(0.01)
                        continue
                    print("in while")
                    frame = framequeue.get()
                    detected_info = YOLO.infer(frame)
                    # 找出置信度大于0.4且面积最大的目标
                    max_area = 0
                    best_info = None
                    for info in detected_info:
                        bbox = info['bbox']
                        confidence = info['confidence']
                        if confidence < 0.7:
                            continue
                        area = (bbox[2] - bbox[0]) * (bbox[3] - bbox[1])
                        if area > max_area:
                            max_area = area
                            best_info = info

                    # 画出检测到的目标
                    if best_info is not None:
                        bbox = best_info['bbox']
                        confidence = best_info['confidence']
                        cls = best_info['class']
                        label = f'{cls} {confidence:.2f}'
                        color = (0, 255, 0)
                        cv2.rectangle(frame, (bbox[0], bbox[1]), (bbox[2], bbox[3]), color, 2)
                        cv2.putText(frame, label, (bbox[0], bbox[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)
                        print((bbox[0], bbox[1]), (bbox[2], bbox[3]), (bbox[2] - bbox[0]) * ((bbox[3] - bbox[1])))
                        mid_x = int((bbox[0] + bbox[2]) / 2)
                        mid_y = int((bbox[1] + bbox[3]) / 2)

                    cv2.imshow('image', frame)
                    cv2.waitKey(1)
                    

                    if abs(mid_x - 318) > 12:
                        x_ready = False
                        x_speed = 0
                        x_speed = max(abs(mid_x - 320) * 0.006, 0.11)
                        if mid_x - 320 > 0:
                            x_speed = -x_speed
                        bot.set_car_motion(0, x_speed)
                        time.sleep(0.1)
                        bot.set_car_motion(0, 0)
                        time.sleep(0.8)
                    else:
                        x_ready = True

                    if abs(mid_y - 354) > 12:
                        y_ready = False
                        y_speed = 0
                        y_speed = max(abs(mid_y - 345) * 0.0020, 0.11)
                        if mid_y - 350 > 0:
                            y_speed = -y_speed
                        bot.set_car_motion(y_speed, 0)
                        time.sleep(0.1)
                        bot.set_car_motion(0, 0)
                        time.sleep(0.8)
                    else:
                        y_ready = True
                    print(x_ready, y_ready)
                    if x_ready and y_ready:
                        print("开始夹取")
                        straight_arm()
                        time.sleep(2)
                        tight_arm()
                        time.sleep(1.2)
                        curl_arm()
                        time.sleep(2)
                        break
                    time.sleep(0.01)
                break
            else:
                bot.set_car_motion(0, 0)

            # 计算FPS
            curr_time = time.time()
            fps = 1 / (curr_time - prev_time)
            prev_time = curr_time

            # 在图像上显示FPS
            cv2.putText(frame, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

            # 显示结果图像
            cv2.imshow('image', frame)

        # 按'q'键退出
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break

    # 释放资源
    bot.set_car_motion(0, 0)
    del bot
    cap.release()
    cv2.destroyAllWindows()
