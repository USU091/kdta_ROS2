#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

int main()
{
    
    Mat src = imread(folder + "lenna.bmp", IMREAD_GRAYSCALE);
    Mat imgAddCenter = src + (src - 125) * 1.0f; 
    Mat histo;
    int channels[] = {0};
    int dims = 1;
    const int hisSize[] = {256};

    float grayLevel[] = {0,256};
    const float *ranges[] = {grayLevel};



    calcHist(&src, 1, channels, noArray(), histo, dims, hisSize, ranges);

    imshow("src", src);
    imshow("imgAddCenter", imgAddCenter);
    
    

    //make graph

    Mat graph(100, 256, CV_8U, Scalar(255));
    normalize(histo, histo, 0, 100, NORM_MINMAX);
    for(int i = 0 ; i < 256; i++)
    {
        line(graph, Point(i,100), Point(i, 100 - cvRound(histo.at<float>(i))),
        Scalar(0));
    }
    imshow("graph", graph);
    


    waitKey(0);
    return 0;
}