#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
	// can bang anh xam
	Mat src = imread("F:\\anh\\cay.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst;
	equalizeHist(src, dst);
	imshow("anh xam goc", src);
	imshow("anh xam sau khi can bang", dst);
	//waitKey(0);

	// can bang anh mau
	//chuyen anh RGB thanh sang HSV, sau do can bang kenh mau V - value (do sang) va bien doi nguoc lai
	Mat src2 = imread("F:\\anh\\tp.jpg", CV_LOAD_IMAGE_COLOR);
	Mat dst2, hsv;
	vector<Mat>hsvchannel;
	cvtColor(src2, hsv, CV_RGB2HSV); // chuyen RGB sang HSV
	split(hsv, hsvchannel); // tach thanh 3 kenh mau
	equalizeHist(hsvchannel[2], hsvchannel[2]); // can bang kenh mau V
	merge(hsvchannel, hsv); // tron anh
	cvtColor(hsv, dst2, CV_HSV2RGB); // chuyen doi nguoc lai
	imshow("anh goc", src2);
	imshow("anh mau can bang", dst2);
	waitKey(0);
}