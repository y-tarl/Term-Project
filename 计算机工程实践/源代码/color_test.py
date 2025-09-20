import cv2
import numpy as np

# 初始化滑块的初始值
def nothing(x):
    pass

# 创建一个窗口
cv2.namedWindow('HSV Adjuster')

# 创建滑块
cv2.createTrackbar('H Min', 'HSV Adjuster', 0, 179, nothing)
cv2.createTrackbar('S Min', 'HSV Adjuster', 0, 255, nothing)
cv2.createTrackbar('V Min', 'HSV Adjuster', 0, 255, nothing)
cv2.createTrackbar('H Max', 'HSV Adjuster', 179, 179, nothing)
cv2.createTrackbar('S Max', 'HSV Adjuster', 255, 255, nothing)
cv2.createTrackbar('V Max', 'HSV Adjuster', 255, 255, nothing)

# 获取摄像头输入
cap = cv2.VideoCapture(0)

while True:
    # 读取每一帧
    ret, frame = cap.read()
    if not ret:
        break
    
    # 转换为HSV颜色空间
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    
    # 获取滑块的当前值
    h_min = cv2.getTrackbarPos('H Min', 'HSV Adjuster')
    s_min = cv2.getTrackbarPos('S Min', 'HSV Adjuster')
    v_min = cv2.getTrackbarPos('V Min', 'HSV Adjuster')
    h_max = cv2.getTrackbarPos('H Max', 'HSV Adjuster')
    s_max = cv2.getTrackbarPos('S Max', 'HSV Adjuster')
    v_max = cv2.getTrackbarPos('V Max', 'HSV Adjuster')
    
    # 设置HSV的阈值
    lower_hsv = np.array([h_min, s_min, v_min])
    upper_hsv = np.array([h_max, s_max, v_max])
    
    # 应用阈值
    mask = cv2.inRange(hsv, lower_hsv, upper_hsv)
    
    # 生成结果图像
    result = cv2.bitwise_and(frame, frame, mask=mask)
    
    # 显示原始图像和结果图像
    cv2.imshow('Original', frame)
    cv2.imshow('Masked', result)
    
    # 按ESC键退出
    if cv2.waitKey(1) & 0xFF == 27:
        break

# 释放资源并关闭窗口
cap.release()
cv2.destroyAllWindows()