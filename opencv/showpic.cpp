#include <opencv2\highgui.hpp>
#include <opencv2\imgproc.hpp>

using namespace cv;

void main(){
	Mat img = imread("pic.jpg");
	//�ı�ߴ�
	Mat imgSize ;
	resize(img,imgSize,Size(300,210),0,0,CV_INTER_LINEAR);
	imshow("ԭͼ",imgSize);
	//��ʴͼ
	Mat erodeElement = getStructuringElement(MORPH_CROSS,Size(10,10));
	Mat dstImg;
	erode(imgSize , dstImg ,erodeElement);
	imshow("��ʴͼ",dstImg);
	//ģ��ͼ
	Mat blurImage;
	blur(imgSize,blurImage,Size(10,10));
	imshow("ģ��ͼ",blurImage);
	//�Ҷ�ͼ
	Mat grayImage;
	cvtColor(imgSize,grayImage,CV_BGR2GRAY);
	imshow("�Ҷ�ͼ",grayImage);
	//����
	Mat edge;
	blur(grayImage,edge,Size(3,3));
	imshow("����",edge);
	//��Ե���
	Canny(edge,edge,3,9,3);
	imshow("��Ե���",edge);
	//�ȴ����������
	waitKey(0);
}