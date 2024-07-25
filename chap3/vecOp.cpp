#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";


int main()
{
    Vec3b  p1, p2(0,0,255);
    p1[0] = 255;

    cout << "p1 : " << p1 << endl;
    cout << "p2 : " << p2 << endl;

    //Scalar
    Scalar grey = 128;
    cout << "grey : " << grey << endl;

    Scalar yellow(0, 255, 255);
    cout << "yellow :" << yellow << endl;

    //Color 
    Mat img1(400, 400, CV_8UC3, yellow);
    Mat img2(400, 400, CV_8UC1, grey);
    Mat img3(400, 400, CV_8UC3, p2);
    Mat img4(400, 400, CV_8UC3, (0, 1, 0));

    imshow("img1", img1);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    
    waitKey(0);

    return 0;

}