#include <iostream>
#include <string>
#include "opencv2/opencv.hpp"

std::string folder = "/home/usu0/ROS2/kdta_ROS2/";
int main()
{

    std::cout <<" hello world;" <<std::endl;
    cv::Mat img;
    img = cv::imread(folder + "lena.bmp");
    cv::imshow("image", img);
    cv::waitKey(0);

    
    return 0;
}