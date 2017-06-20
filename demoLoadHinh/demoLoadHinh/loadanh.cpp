#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// load hinh	
	//IplImage * img = cvLoadImage("F:\\anh\\doremon.jpg");
	//if (img != NULL)
	//{
	//	cvNamedWindow("My window"); // dat ten cho window
	//	cvShowImage("My window", img); // show window do len
	//	cvWaitKey(); // doi nguoi dung nhap 1 phim bat ki
	//	cvReleaseImage(&img); // giai phong vung nho
	//	cvDestroyWindow("My window"); // dong cua so
	//}
	//return 0;

	// chuyen doi khong gian mau
	cout << "xin chao ban den phan chuyen doi anh!!!" << endl;
	Mat src = imread("F:\\anh\\doremon.jpg", CV_LOAD_IMAGE_COLOR); // CV_LOAD_IMAGE_COLOR = 1
	Mat gray, hsv;
	cvtColor(src, gray, CV_BGR2GRAY); // chuyen RGB sang gray
	cvtColor(src, hsv, CV_BGR2HSV); // chuyen RGB sang HSV
	imshow("src", src);
	imshow("gray", gray);
	imshow("hsv", hsv);
	waitKey(); // doi den phim nao duoc nhan moi tat
}