#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	cout << "chuong trinh doi anh nhi phan" << endl;
	Mat src = imread("F://anh//lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat dst = src.clone();
	Mat dst2 = src.clone();
	Mat dst3 = src.clone();

	// cach 1: nguong dong
	//adaptiveThreshold(src, dst, 255, CV_ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 35, 5);

	// cach 2: dung nguong nhi phan (nguong tinh)
	threshold(src, dst, 50, 255, CV_THRESH_BINARY); // tham so thu 3 la nguong nhi phan
	threshold(src, dst2, 100, 255, CV_THRESH_BINARY);
	threshold(src, dst3, 150, 255, CV_THRESH_BINARY);

	imshow("anh nguon", src);
	imshow("t = 50", dst);
	imshow("t = 100", dst2);
	imshow("t = 150", dst3);

	waitKey(0);

	return 1;
}