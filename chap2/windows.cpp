#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

string folder = "/home/usu0/ROS2/kdta_ROS2/data/";
int main()
{
    Mat img;
    img = imread(folder+"lena.bmp");
    namedWindow("lena");
    imshow("lena", img);
    int key = waitKey(0);
    cout << key << endl;

    Size size ;
    size.height = 100;
    size.width = 50;
    destroyWindow("lena");

    imshow("lena", img);
    resizeWindow("lena", size);
    waitKey(0);

    return 0;

}
