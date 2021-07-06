#ifndef OPM_GENERATOR_H
#define OPM_GENERATOR_H

#include <opencv2/opencv.hpp>
#include <nav_msgs/OccupancyGrid.h>

class OPY_GENERATOR
{
public:
    ////用于生成地图的灰度图
    cv::Mat image_src;
    ////生成的占用网格栅图
    nav_msgs::OccupancyGrid opy_map;
    ////构造函数
    OPY_GENERATOR(cv::Mat IMAGE_src,float RESOLUTION);
    void map_generate();

private:
    ////image_src的行列
    uint32_t row;
    uint32_t column;
    ////opy_map的高度、宽度、分辨率
    uint32_t height;
    uint32_t width;
    float resolution;

};

#endif