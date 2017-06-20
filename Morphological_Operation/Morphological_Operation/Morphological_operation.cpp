#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat img = imread("F:\\anh\\j.png", 0); // load anh binary
	Mat dstDialiation, dstErosion, dstOpenning, dstClosing;
	imshow("anh src", img);
	
	// toan tu co
	erode(img, dstErosion, Mat()); // mac dinh Mat la kernel 3 x 3
	imshow("Erosion", dstErosion);

	// toan tu gian
	dilate(img, dstDialiation, Mat());
	imshow("Dialiation", dstDialiation);

	// thay doi kernel
	Mat element5(5, 5, CV_8U, Scalar(1));

	// toan tu mo
	morphologyEx(img, dstOpenning, MORPH_OPEN, element5);
	imshow("Openning", dstOpenning);
	
	// toan tu dong
	morphologyEx(img, dstClosing, MORPH_CLOSE, element5);
	imshow("Closing", dstClosing);

	waitKey(0);
}