#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat dst;
    bilateralFilter(src, dst, -1, 10, 5);
    



    imshow("src", src);
    imshow("dst", dst);

    waitKey(0);

    return 0;
}
