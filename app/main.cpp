#include <ros/ros.h>
#include <nav_msgs/OccupancyGrid.h>
#include <opencv2/opencv.hpp>
#include "opm_generator.hpp"

#define resolution 0.01

using namespace cv;


int main(int argc,char** argv)
{
    ros::init(argc,argv,"image2opymap");
    ros::NodeHandle n;

    //// 读取RGB测试图像
    Mat test_rgb = imread("/home/dango/dango_file/planning study/image2opm/image2opm_ws/src/image2opm_pkg/test_image/1");
    //imshow("image rgb",test_rgb);
    //waitKey(0);
    //// 测试图像转gray
    Mat test_gray;
    cvtColor(test_rgb,test_gray,CV_BGR2GRAY);

    //// 创建image转occupangrid的类
    OPY_GENERATOR grid_generator(test_gray,resolution);
    grid_generator.map_generate();

    //// 发布OccupancyGrid话题
    ros::Publisher opy_pub = n.advertise<nav_msgs::OccupancyGrid>("opy_grid",1);

    ros::Rate loop_rate(100);
    while(ros::ok())
    {
        opy_pub.publish(grid_generator.opy_map);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;

}