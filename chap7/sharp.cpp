#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "rose.bmp", IMREAD_GRAYSCALE);
    vector<Mat> dsts;

    Mat dst;

    for(int alpha = 1; alpha <11; alpha++)
    {
        Mat blurred;
        GaussianBlur(src, blurred, Size(0,0), 3);
        Mat dst = (1 + alpha) * src - alpha * blurred;
        dsts.push_back(dst);
    }


    imshow("src", src);

    int i = 1;
    for(auto dst : dsts)
    {
        imshow("dst" + to_string(i), dst);
        i++;
    }

    waitKey(0);

    return 0;
}
