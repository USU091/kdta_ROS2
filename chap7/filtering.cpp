#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    //float data[] = {-1,-1,0,-1,0,1,0,1,1};
    float data[] = {1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9,1.0/9};
    Mat emboss(3,3,CV_32F, data);
    Mat dst;

    filter2D(src, dst, -1, emboss, Point(-1, -1), 10);  //blurr

    imshow("src", src);
    imshow("dst", dst);
    waitKey(0);

    
    waitKey(0);

    return 0;

}
    
