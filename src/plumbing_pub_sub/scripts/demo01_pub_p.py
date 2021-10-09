#! /usr/bin/env python
#coding=utf-8


# from os import putenv
from time import daylight
import rospy
from rospy.core import _ros_atexit
# from std_msgs import msg
from std_msgs.msg import String  # 发布的消息类型

'''
    使用欧Python 实现消息发布：
    1. 导包；
    2. 初始化ros节点
    3. 创建发布者对象；
    4. 编写发布逻辑并发布数据。
'''


if __name__ ==  "__main__":
    
    # 2. 初始化ros节点
    rospy.init_node("sanDai")  #传入节点名称
    # 3. 创建发布者对象；
    pub = rospy.Publisher("che",String,queue_size=10)
    # 4. 编写发布逻辑并发布数据。 
    # 创建数据
    msg = String()
    #设置计数器
    count = 0
    #指定发布频率
    rate = rospy.Rate(1)
    # 使用循环发布数据
    rospy.sleep(3)  #发布数据之前休眠3秒，为的是让发布者完成注册之后再进行发布数据；
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello" + str(count)
        # 发布数据
        pub.publish(msg)
        rospy.loginfo("发布的数据：%s",msg.data)
        rate.sleep()

"""
记录一下遇到的错误：
1. 如果Python文件中有中文，会抛出异常`SyntaxError: Non-ASCII character '\xe5' in file`
    
    解决方法：在Python文件前加上一句
    ```python
    #coding=utf-8
    ```
2. 在运行python时，抛出异常`import: not authorized `rospy' @ error/constitute.c/WriteImage/1028.`

    解决方法：在python文件前面加上一句  --> 指定一下解释器
    ```python
    #! /usr/bin/env python
    ```
3. 如果吧`#coding=utf-8`放在第一行，`#! /usr/bin/env python`放在第二行，还是会出现问题2，所以他们之间的顺序应该如下：
    ```python
    #! /usr/bin/env python
    #coding=utf-8
    ```
"""        