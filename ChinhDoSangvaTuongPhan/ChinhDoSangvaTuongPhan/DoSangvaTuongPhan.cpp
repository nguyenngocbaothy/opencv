#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	cout << "chuong trinh chinh do sang toi" << endl;
	Mat src = imread("F:\\anh\\doremon.jpg", 1);
	Mat dst = src.clone(); // copy anh src thanh anh dst
	Mat dst2 = src.clone();
	
	int anpha = 2.0; // do tuong phan gap doi
	int beta = 30; // do sang 

	// duyet tung diem trong tam hinh
	for (int i = 0; i < src.rows; i++)
	{
		for (int j = 0; j < src.cols; j++)
		{
			for (int k = 0; k < 3; k++) // k = 3 tuong ung voi 3 mau R, G, B 
			{
				// g(x,y) = anpha * f(x,y) + beta
				dst.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(anpha * (src.at<Vec3b>(i, j)[k]) + beta);
				dst2.at<Vec3b>(i, j)[k] = saturate_cast<uchar>(4.0 * (src.at<Vec3b>(i, j)[k]) + 60);
			}
		}
	}

	// hien anh
	imshow("anh goc", src);
	imshow("tphan: 2.0", dst);
	imshow("tphan: 4.0", dst2);
	waitKey(0);
	return 0;
}