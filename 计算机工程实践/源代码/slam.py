#!/usr/bin/env python

import rospy
from geometry_msgs.msg import PoseStamped
from move_base_msgs.msg import MoveBaseActionResult
from std_msgs.msg import Header
import socket
import time

goal_reached = False

def start_server(header, pub, host='0.0.0.0', port=65432):  # 监听所有接口
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)  # 设置SO_REUSEADDR选项
        s.bind((host, port))
        s.listen()
        print(f'Server listening on {host}:{port}')

        while True:
            conn, addr = s.accept()
            with conn:
                print(f'Accepted connection from {addr}')
                while True:
                    data = conn.recv(1024)
                    if not data:
                        break
                    command = data.decode().strip()
                    print('Received:', command)
                    if command == 'A':
                        print("GO_TO_A")
                        go_to_A(header, pub)
                    elif command == 'B':
                        print("GO_TO_B")
                        go_to_B(header, pub)
                    elif command == 'C':
                        print("GO_TO_C")
                        go_to_C(header, pub)
                    time.sleep(0.1)

def result_callback(data):
    global goal_reached
    if data.status.status == 3:  # status 3 means the goal was reached
        rospy.loginfo("Goal reached!")
        goal_reached = True
    else:
        rospy.loginfo("Current status: %d", data.status.status)

def go_to_A(header, pub):
    positionA = PoseStamped()
    positionA.header = header
    positionA.pose.position.x = 2.82  # 设置目标点的x坐标
    positionA.pose.position.y = -1.0  # 设置目标点的y坐标
    positionA.pose.position.z = 0.00495
    positionA.pose.orientation.x = 0.0
    positionA.pose.orientation.y = 0.0
    positionA.pose.orientation.z = 0.0
    positionA.pose.orientation.w = 1.0

    rospy.loginfo("Publishing goal: %s", positionA)
    pub.publish(positionA)

def go_to_B(header, pub):
    positionB = PoseStamped()
    positionB.header = header
    positionB.pose.position.x = 2.11  # 设置目标点的x坐标
    positionB.pose.position.y = -2.5  # 设置目标点的y坐标
    positionB.pose.position.z = 0.00438
    positionB.pose.orientation.x = 0.0
    positionB.pose.orientation.y = 0.0
    positionB.pose.orientation.z = 0.0
    positionB.pose.orientation.w = 1.0

    rospy.loginfo("Publishing goal: %s", positionB)
    pub.publish(positionB)

def go_to_C(header, pub):
    positionC = PoseStamped()
    positionC.header = header
    positionC.pose.position.x = 0.26  # 设置目标点的x坐标
    positionC.pose.position.y = -0.0125  # 设置目标点的y坐标
    positionC.pose.position.z = 0.0075
    positionC.pose.orientation.x = 0.0
    positionC.pose.orientation.y = 0.0
    positionC.pose.orientation.z = 0.0
    positionC.pose.orientation.w = 1.0

    rospy.loginfo("Publishing goal: %s", positionC)
    pub.publish(positionC)

def go_to_Position(header, pub, position_x, position_y, position_z, orientation_x, orientation_y, orientation_z, orientation_w):
    position = PoseStamped()
    position.header = header
    position.pose.position.x = position_x  # 设置目标点的x坐标
    position.pose.position.y = position_y  # 设置目标点的y坐标
    position.pose.position.z = position_z
    position.pose.orientation.x = orientation_x
    position.pose.orientation.y = orientation_y
    position.pose.orientation.z = orientation_z
    position.pose.orientation.w = orientation_w

    rospy.loginfo("Publishing goal: %s", position)
    pub.publish(position)

def publish_goal():
    rospy.init_node('publish_goal_and_check_result', anonymous=True)
    pub = rospy.Publisher('/move_base_simple/goal', PoseStamped, queue_size=10)

    header = Header()
    header.seq = 0
    header.stamp = rospy.Time.now()
    header.frame_id = "map"  # 或者使用你实际需要的frame_id

    rospy.Subscriber('/move_base/result', MoveBaseActionResult, result_callback)

    start_server(header, pub)

if __name__ == '__main__':
    try:
        publish_goal()
    except rospy.ROSInterruptException:
        pass
