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

    for(int ksize = 3; ksize <20; ksize +=2)
    {
        Mat dst;
        blur(src, dst, Size(ksize, ksize));
        dsts.push_back(dst);
    }


    imshow("src", src);

    int i = 3;
    for(auto dst : dsts)
    {
        imshow("dst" + to_string(i), dst);
        i+=2;
    }

    waitKey(0);

    return 0;
}
