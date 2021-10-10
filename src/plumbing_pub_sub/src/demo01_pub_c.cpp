#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>
/*
    发布方实现：
        1.包含头文件；
            ROS 中文文本类型 --> std_msgs/String.h
        2.初始化 ros 节点；
        3.创建节点句柄；
        4.创建发布者对象；
        5.编写发布逻辑并发布数据。
*/


int main(int argc, char *argv[])
{
    // 设置编码：防止中文乱码
    setlocale(LC_ALL, "");
    // 2.初始化 ros 节点；
    ros::init(argc, argv, "erGouZi");
    // 3.创建节点句柄；
    ros::NodeHandle nh;
    // 4.创建发布者对象；
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    // 5.编写发布逻辑并发布数据。
    // 需求:要求以 10HZ 的频率发布数据,并且文本后添加编号;
    // 先创建被发布的消息
    std_msgs::String msg;
    // 发布频率
    ros::Rate rate(1);
    // 设置编号
    int count = 0;
    // 编写循环,循环中发布消息
        //设置休眠时间，可以等待publisher 在master中注册，就不会导致数据丢失
    ros::Duration(1).sleep(); 
    while (ros::ok())
    {
        count++;
        // 实现字符串拼接数字
        std::stringstream ss;
        ss << "hello ---> " << count;
        msg.data = ss.str();
        // msg.data = "hello";
        pub.publish(msg);
        // 添加日志
        ROS_INFO("发布的数据是: %s", ss.str().c_str());
        rate.sleep();

        ros::spinOnce(); //官方建议，处理回调函数；（发布方这里没有回调函数）
    }
    
    return 0;
}
