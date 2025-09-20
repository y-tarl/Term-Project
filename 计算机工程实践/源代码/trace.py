import cv2
import time
import inferapi
from Transbot_Lib import Transbot

# 创建Transbot对象 bot
bot = Transbot()

# 启动接收数据 
bot.create_receive_threading()


# 初始化YOLO模型
YOLO = inferapi.ExternalInference('traffic.pt', 320)

# 打开摄像头
cap = cv2.VideoCapture(1)  # 0表示读取默认的摄像头

if not cap.isOpened():
    print("Error: Cannot open video stream or file")
    exit()

# 计算FPS相关变量
prev_time = 0
fps = 0
see_cnt = 0
speed_front = 0
uturn_flag = 0
while True:
    ret, frame = cap.read()
    if not ret:
        break

    # 推理
    detected_info = YOLO.infer(frame)
    mid_x = -1
    height = -1
    # 画出检测到的目标
    for info in detected_info:
        bbox = info['bbox']
        confidence = info['confidence']
        if confidence < 0.5:
            continue
        cls = info['class']
        label = f'{cls} {confidence:.2f}'
        color = (0, 255, 0)
        cv2.rectangle(frame, (bbox[0], bbox[1]), (bbox[2], bbox[3]), color, 2)
        print((bbox[0], bbox[1]), (bbox[2], bbox[3]), (bbox[2] - bbox[0]) * ((bbox[3] - bbox[1])))
        cv2.putText(frame, label, (bbox[0], bbox[1] - 10), cv2.FONT_HERSHEY_SIMPLEX, 0.9, color, 2)

        if cls == 'straight':
            height = bbox[3] - bbox[1]
            mid_x = (bbox[0] + bbox[2]) // 2

        if cls == 'uturn':
            uturn_flag = 1
    
    speed_x = 0

    if uturn_flag == 1:
        uturn_flag = 0
        bot.set_car_motion(0, -1)
        last_time = time.time()
        while time.time() - last_time < 1.8:
            ret, frame = cap.read()
            cv2.imshow('YOLOv5 Inference', frame)
            time.sleep(0.05)
        continue

    if mid_x == -1:
        if see_cnt < 2:
            see_cnt += 1
            continue
        bot.set_car_motion(0, 0)
    else:
        print(mid_x)
        if mid_x < 220:
            speed_x = min(0.3, (320 - mid_x) * 0.0015)
        elif mid_x > 420:
            speed_x = -min(0.3, (mid_x - 320) * 0.0015)
        else:
            speed_x = 0

        if height < 80:
            speed_front = 0.15
        elif height > 200:
            speed_front = 0

        bot.set_car_motion(speed_front, speed_x)

    # 计算FPS
    curr_time = time.time()
    fps = 1 / (curr_time - prev_time)
    prev_time = curr_time

    # 在图像上显示FPS
    cv2.putText(frame, f'FPS: {fps:.2f}', (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    # 显示结果图像
    cv2.imshow('YOLOv5 Inference', frame)

    # 按'q'键退出
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放资源
bot.set_car_motion(0, 0)
del bot
cap.release()
cv2.destroyAllWindows()
