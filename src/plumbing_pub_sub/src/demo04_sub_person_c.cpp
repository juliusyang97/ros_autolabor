#include "ros/ros.h"
#include "plumbing_pub_sub/person.h"

/* 
    订阅方：订阅消息
    1.包含头文件；
    2.初始化 ros 节点；
    3.创建节点句柄；
    4.创建订阅者对象；
    5.编写回调函数、处理订阅到数据；
    6.调用spin()函数。
*/

void doPerson(const plumbing_pub_sub::person::ConstPtr &person){
    ROS_INFO("订阅人的消息：%s, %d, %.2f", person->name.c_str(), person->age, person->height);
    
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("这是订阅方实现");
    // 2.初始化 ros 节点；
    ros::init(argc,argv,"jiaZhang");
    // 3.创建节点句柄；
    ros::NodeHandle nh;
    // 4.创建订阅者对象；
    ros::Subscriber sub = nh.subscribe("liaoTian",10,doPerson);
    // 5.编写回调函数、处理订阅到数据；

    // 6.调用spin()函数。
    ros::spin();
    return 0;
}
