#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);

    Mat img = imread(folder + "lenna.bmp", IMREAD_COLOR);
    Mat imgGray = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);

    Mat cvtGrey;
    cvtColor(img, cvtGrey, COLOR_BGR2GRAY);
    Mat imgAdd = imgGray + 50;
    Mat imgAddCenter = imgGray + (imgGray - 125) * 1.0f;

    imshow("img", img);
    imshow("imgGray", imgGray);
    imshow("cvtGrey", cvtGrey);
    imshow("imgAdd", imgAdd);
    imshow("imgAddCenter", imgAddCenter);
    waitKey(0);




    return 0;
}