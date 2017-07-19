#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;

void main(){
	Mat img = imread("pic.jpg");
	//¸Ä±ä³ß´ç
	Mat imgSize ;
	resize(img,imgSize,Size(300,210),0,0,CV_INTER_LINEAR);
	imshow("Ô­Í¼",imgSize);
	//¸¯Ê´Í¼
	Mat erodeElement = getStructuringElement(MORPH_CROSS,Size(10,10));
	Mat dstImg;
	erode(imgSize , dstImg ,erodeElement);
	imshow("¸¯Ê´Í¼",dstImg);
	//Ä£ºýÍ¼
	Mat blurImage;
	blur(imgSize,blurImage,Size(10,10));
	imshow("Ä£ºýÍ¼",blurImage);
	//»Ò¶ÈÍ¼
	Mat grayImage;
	cvtColor(imgSize,grayImage,CV_BGR2GRAY);
	imshow("»Ò¶ÈÍ¼",grayImage);
	//½µÔë
	Mat edge;
	blur(grayImage,edge,Size(3,3));
	imshow("½µÔë",edge);
	//±ßÔµ¼ì²â
	Canny(edge,edge,3,9,3);
	imshow("±ßÔµ¼ì²â",edge);
	//µÈ´ýÈÎÒâ¼ü°´ÏÂ
	waitKey(0);
}