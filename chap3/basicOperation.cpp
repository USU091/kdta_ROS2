#include <iostream>
#include "opencv2/opencv.hpp"


using namespace cv;

String folder = "/home/usu0/ROS2/kdta_ROS2/data";


int main()
{
    //Point
    Point pt1;
    pt1.x = 5;
    pt1.y = 10;

    Point pt2(6,7);

    std::cout << pt1 << std::endl;
    std::cout << pt2 <<std::endl;


    //Size

    Size sz1;
    sz1.height = 10;
    sz1.width = 20;

    Size sz2(50, 100);

    std::cout << sz1 << std::endl;
    std::cout << sz2 << std::endl;
    std::cout << sz1.area() << "size2 :: " <<  sz2.area() << std::endl;


    return 0;


}