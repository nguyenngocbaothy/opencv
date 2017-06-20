#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
	cout << "chuong trinh loc anh" << endl;

	// c1:
	//IplImage * src = cvLoadImage("F:\\anh\\lena.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	//IplImage * dst = cvCreateImage(cvSize(src->width, src->height), IPL_DEPTH_8U, 1);

	//cvSmooth(src, dst, CV_BLUR, 3, 3); // bo loc mean 

	//cvNamedWindow("src"); // dat ten cho window
	//cvShowImage("src", src); // show window do len
	//cvNamedWindow("dst"); 
	//cvShowImage("dst",dst);

	// c2: 
	Mat src = imread("F:\\anh\\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	//blur(src, dst, Size(3, 3)); // bo loc mean (trung binh) anh xam
	//medianBlur(src, dst, 5); // bo loc anh median (trung vi)
	GaussianBlur(src, dst, Size(5, 5), 1.5); // tham so thu 4 la vi tri x (tam kernel)
	imshow("src", src);
	imshow("dst", dst);

	Mat src2 = imread("F:\\anh\\lenamau.jpg", CV_LOAD_IMAGE_COLOR);
	Mat dst2;
	//blur(src2, dst2, Size(3, 3)); // bo loc mean anh mau
	//medianBlur(src2, dst2, 5);
	GaussianBlur(src2, dst2, Size(5, 5), 1.5);
	imshow("src2", src2);
	imshow("dst2", dst2);

	waitKey(0);
}