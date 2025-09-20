from Transbot_Lib import Transbot
import time
# 创建Transbot对象 bot
# Create Transbot object as bot
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
    bot.set_uart_servo_angle(9, 40)  
    time.sleep(0.3)

# 加紧机械臂
def tight_arm():
    bot.set_uart_servo_angle(9, 118)  
    time.sleep(0.3)

bot = Transbot()

# 启动接收数据 
# Start receiving data
bot.create_receive_threading()
bot.set_car_motion(0, 0)
# bot.set_uart_servo_angle(7, 70)  
# bot.set_uart_servo_angle(8, 200)  
# bot.set_uart_servo_angle(9, 150)  
release_arm()
straight_arm()
# straight_arm()
del bot
