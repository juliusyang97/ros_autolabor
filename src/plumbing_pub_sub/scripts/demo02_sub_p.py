#! /usr/bin/env python
#coding=utf-8

import rospy
from std_msgs.msg import String

"""
    订阅实现流程：
        1. 导包；
        2. 初始化节点；
        3. 创建订阅者对象；
        4. 回调函数处理数据；
        5. spin()


"""

def doMsg(msg):
    rospy.loginfo("我订阅的数据：%s",msg.data)

if __name__ == "__main__":
    
    # 2. 初始化节点；
    rospy.init_node("huahua")
    #3. 创建订阅者对象；
    sub = rospy.Subscriber("che",String,doMsg,queue_size=10)
    #4. 回调函数处理数据；

    #5. spin()
    rospy.spin()