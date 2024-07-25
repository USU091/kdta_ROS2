#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";


int main()
{
    float data1[] = {1,1,2,3};
    float *data2 = new float[4];

    data2[0] = 1;
    data2[1] = 1;
    data2[2] = 2;
    data2[3] = 3;

    Mat mat1(2,2,CV_32FC1, data1);
    Mat mat2(2,2,CV_32FC1, data2);

    cout << "mat1 : \n" << mat1 << endl;
    cout << "mat2 : \n" << mat2 << endl;

    delete data2;

    return 0;

}