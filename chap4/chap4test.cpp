#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

String folder = "/home/usu0/ROS2/kdta_ROS2/data/";

void onMouse(int event, int x, int y, int flags, void *data);
struct Mydata
{
    Point ptOld;
    Point ptNew;
    Mat img;
    Mat background;
    Scalar white = Scalar(255, 255, 255);
    Scalar yellow = Scalar(0, 255, 255);
    Scalar blue = Scalar(255, 0, 0);
    Scalar green = Scalar(0, 255, 0);
    Scalar red = Scalar(0, 0, 255);
    vector<Vec3b> mouseBGR;
    bool flag = false;
};

int main()
{
    Mydata mydata;
    FileStorage fs;
    mydata.img = imread(folder + "lenna.bmp");
    mydata.background = mydata.img.clone();
    // Mat lenImg = imread(folder + "lenna.bmp");
    // imshow("lenImg", lenImg);
    // waitKey(0);

    //마우스 따라 다니는 사각형

    namedWindow("img");
    setMouseCallback("img", onMouse, (void *)&mydata);

    imshow("img", mydata.img);

    int keycode = waitKey(0);
    if(keycode == 27)
    {
        fs.open(folder + "mouseBGRPoint.json", FileStorage::WRITE);
        fs << "mouseBGR" << mydata.mouseBGR;
        fs.release();
    }
    destroyAllWindows();
    return 0;

}


void onMouse(int event, int x, int y, int flags, void *data)
{
    Mydata *ptr = (Mydata *)data;
    switch (event)
    {
    case EVENT_LBUTTONDOWN:
        cout << "mouse left button down" << x << y << endl;
        //cout << "image bgr :::" << ptr->img << endl;
        ptr->ptOld = Point(x, y);
        ptr->mouseBGR.push_back(ptr->background.at<Vec3b>(y, x));
        ptr->flag = true;
        break;
    case EVENT_LBUTTONUP:
        cout << "mouse left button up" << x << y << endl;
        ptr->flag = false;
        break;
    case EVENT_MOUSEMOVE:
        //if (ptr->flag & EVENT_FLAG_LBUTTON)
        {
            ptr->background.copyTo(ptr->img);

            rectangle(ptr->img,Point(x-10, y-10), Point(x+10, y+10), ptr->red, -1);

            imshow("img", ptr->img);
            ptr->ptOld = Point(x, y);
        }
    }
}

