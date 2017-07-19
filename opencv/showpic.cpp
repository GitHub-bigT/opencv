#include <iostream>
#include <core.hpp>
#include <imgproc.hpp>
#include <highgui\highgui.hpp>

using namespace cv;

void main(){
	Mat img = imread("pic.jpg",1);
	Mat imgSize ;
	resize(img,imgSize,Size(1000,700),0,0,CV_INTER_LINEAR);
	namedWindow("picture");
	imshow("pic",imgSize);
	waitKey(60000);
}