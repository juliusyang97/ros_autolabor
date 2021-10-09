#! /usr/bin/env python 
#coding=utf-8

import rospy 
from plumbing_pub_sub.msg import person


'''
    发布方：发布人的消息
        1. 导包；
        2. 初始化ROS节点；
        3. 创建发布者对象；
        4. 组织发布逻辑并发布对象。
'''
if  __name__ == "__main__":
    # 2. 初始化ROS节点；
    rospy.init_node("daMa")
    # 3. 创建发布者对象；
    pub = rospy.Publisher('jiaoSheTou',person,queue_size=10)
    # 4. 组织发布逻辑并发布对象。
    # 4-1. 创建person数据
    p = person()
    p.name = "奥特曼"
    p.age = 8
    p.height = 1.85
    # 4-2. 创建 Rate 对象
    rate = rospy.Rate(1)
    # 4-3. 循环发布数据
    while not rospy.is_shutdown():
        pub.publish(p)
        rospy.loginfo("发布的消息：%s,%d,%.2f",p.name,p.age,p.height)
        rate.sleep()
