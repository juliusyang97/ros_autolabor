#include "ros/ros.h"

int main(int argc, char  *argv[])
{
    // 解决乱码问题
    // 1. 第一种解决方法：
    setlocale(LC_ALL, "");
    // 2. 第二种解决方法：
    // setlocale(LC_CTYPE, "zh_CN.utf8");

    ros::init(argc,argv,"hello_vscode");
    ROS_INFO("hhha,哈哈");


    return 0;
}
