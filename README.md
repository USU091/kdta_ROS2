# kdta_ROS2
ROS2 수업


#0724 

1. copyTo(이미지 복사)
    Mat img = imread("deer.jpg", 0);

    Mat img_copy;
    img.copyTo(img_copy);

src.copyTo(dest) : src이미지를 dest에 복사

=> oepncv에서 이미지(Mat)는 포인터 값을 의미함
위 선언된 img, img_copy 변수는 각각의 주소값을 띄게 되며, img의 주소값에 있는 이미지가 img_copy 주소값에 복사된다. 이 때 둘은 다른 주소값을 가지고 있으므로 원형을 보존하고 복사된 이미지를 수정할 수 있다는 점에서 copyTo()가 유용하게 사용됨




#0726
1. Canny()
=> 에지 검출 방법은 그래디언트 크기만을 기준으로 에지 픽셀을 검출하기 때문에 임계값에 민감하고 에지 픽셀이 두껍게 표현되는 문제점이 있는데 이 단점을 해결 할 수 있는 방법을 캐니가 조건 제시하였다.
