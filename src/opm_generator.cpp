#include "opm_generator.hpp"
#include "vector"
#include "ros/ros.h"

using namespace cv;



OPY_GENERATOR::OPY_GENERATOR(cv::Mat IMAGE_src,float RESOLUTION)
{
    //// image_src初始化
    image_src = IMAGE_src;
    row = IMAGE_src.rows;
    column = IMAGE_src.cols;
    //imshow("image_src",image_src);
    ROS_INFO("image row: %d",row);
    ROS_INFO("image column: %d",column);

    //// opy_map初始化
    resolution = RESOLUTION;
    width = column;
    height = row;
    opy_map.info.width=width;
    opy_map.info.height=height;
    std::vector<int8_t>data(width*height,-1);
    opy_map.data=data;
    opy_map.info.resolution = RESOLUTION;
    opy_map.header.frame_id = "Grid";
    ROS_INFO("occupancy grid map height : %d",height);
    ROS_INFO("occupancy grid map width : %d",width);
    ROS_INFO("occupancy grid map data1 : %d \n",opy_map.data[0]);
    //waitKey(0);
}

void OPY_GENERATOR::map_generate()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            image_src.at<uint8_t>(i,j)>100?opy_map.data[width*(i)+j]=100:opy_map.data[width*(i)+j]=0;
            //ROS_INFO("DATA : %d",opy_map.data[width*(i)+j]);
        }
    }
}