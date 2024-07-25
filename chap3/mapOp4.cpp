#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";


int main()
{
    Mat mat1 = Mat::zeros(3, 4, CV_8UC1); //unsigned character type
    cout << "Before Map1 : " << mat1 << endl;


    for(int i = 0; i < mat1.rows; i++)
    {
        for(int j = 0; j < mat1.cols; j++)
        {

            mat1.at<char>(i, j)++;
        }

    }
    cout << "After mat1 : " << endl <<mat1 << endl;

    for(int i = 0; i < mat1.rows; i++)
    {
         uchar *p = mat1.ptr<uchar>(i);
        for(int j = 0; j < mat1.cols; j++)
        {

            p[j]++;
        }

    }

    cout << "After ptr mat1 : " << endl << mat1<< endl;

    for(auto it = mat1.begin<uchar>(); it != mat1.end<uchar>(); it++)
    {

        (*it)++;
    }

    cout << "after iterator mat1 : " << endl << mat1 << endl;

    return 0;
}