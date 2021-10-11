#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

/*
    发布方实现：发布人的消息
    1.包含头文件；
    2.初始化 ros 节点；
    3.创建节点句柄；
    4.创建发布者对象；
    5.编写发布逻辑、发布数据。
*/


int main(int argc, char *argv[])
{
    // 设置编码；
    setlocale(LC_ALL, "");
    // 2.初始化 ros 节点；
    ros::init(argc, argv, "banZhuRen");
    // 3.创建节点句柄；
    ros::NodeHandle nh;
    // 4.创建发布者对象；
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::person>("liaoTian",10);
    // 5.编写发布逻辑、发布数据。
    // 5.1创建发布数据；
    plumbing_pub_sub::person person;
    person.name = "张三";
    person.age = 24;
    person.height = 1.825;
    // 5.2设置发布频率；
    ros::Rate rate(1);
    // 5.3循环发布；
    while (ros::ok()){
        // 修改数据
        person.age += 1;
        // 核心：数据发布
        pub.publish(person);
        // 添加日志
        ROS_INFO("这是发布的消息：%s, %d, %.2f", person.name.c_str(), person.age, person.height);
        // 设置休眠
        rate.sleep();
        // 建议调用回调函数
        ros::spinOnce();
    }
    
    return 0;
}
