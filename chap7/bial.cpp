#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat noise(src.size(), CV_32FC1);

    int stddev = 10;
    randn(noise, 0, stddev);
    //src = src + noise;
    add(src, noise, src, Mat(), CV_8U);

    Mat dst1, dst2;
    GaussianBlur(src, dst1, Size(0,0), 5);
    bilateralFilter(src, dst2, -1, 10, 5);

    

    imshow("src", src);
    imshow("dst", dst1);
    imshow("dst2", dst2);

    waitKey(0);

    return 0;
}
