#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "hawkes.bmp", IMREAD_GRAYSCALE);
    Mat add, center, minmax, dst;
    double gmin, gmax;

    add = src + 50; 
    minMaxLoc(src, &gmin, &gmax);
    minmax = (src - gmin) * 255 / (gmax - gmin);
    equalizeHist(src, dst);


    imshow("src", src);
    imshow("equalization", dst);
    imshow("add", add);
    imshow("center", center);
    imshow("minmax", minmax);

    

    waitKey(0);
    return 0;
}