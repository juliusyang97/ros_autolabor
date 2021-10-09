#! /usr/bin/env python
#coding=utf-8 

# 现象：当不配置 CMakeLists.txt 执行 python 文件抛出异常；
# 异常：/usr/bin/env: "python": 没有文件或目录
# 测试：直接在终端输入 /usr/bin/env python，，，对比一下/usr/bin/env python3
# 原因：当前 noetic 使用的是 python3
# 解决：
#     1. 直接声明解释器为 python3 （不建议）
#     2. 通过软链接将 python 链接到 python3 （建议）：
#        sudo ln -s /usr/bin/python3 /usr/bin/python

# 我使用的 Ubuntu16 + kinetic 不会出现该问题

# 1.导包
import rospy 

if __name__ == "__main__":

    # 2.初始化 ROS 节点
    rospy.init_node("Hello_Vscode_p")
    #3.日志输出 HelloWorld  
    rospy.loginfo("Hello VScode, 我是 Python ....")  
