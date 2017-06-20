#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat src = imread("F:\\anh\\dog.jpg", CV_LOAD_IMAGE_COLOR);
	Mat dst1, dst2, dst_laplace;
	imshow("anh xam", src);

	GaussianBlur(src, src, Size(3, 3), 2); // loc anh
	imshow("anh loc", src);

	// thuat toan canny
	double t1 = 30, t2 = 200; // nguong duoi, nguong tren
	Canny(src, dst1, t1, t2, 3, false);
	t1 = 100, t2 = 120;
	Canny(src, dst2, t1, t2, 3, false);
	imshow("canny nguong 1", dst1);
	imshow("canny nguong 2", dst2);


	// thuat toan laplace
	Mat abs_dst;
	Laplacian(src, dst_laplace, CV_16S, 3, 1, 0, BORDER_DEFAULT); // 1, 0: gia tri mac dinh
	convertScaleAbs(dst_laplace, abs_dst); // chuyen doi anh laplace dst sang anh CV_8U
	imshow("laplace", abs_dst);

	
	// thuat toan gradient theo huong x, y voi bo loc sobel
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	Mat grad;

	// gradient x
	Sobel(src, grad_x, CV_16S, 1, 0, 3, 1, 0, BORDER_DEFAULT); // su dung mat na sobel
	convertScaleAbs(grad_x, abs_grad_x); 

	// gradient y
	Sobel(src, grad_y, CV_16S, 0, 1, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad); 
	imshow("gradient", grad);

	
	// edge detection
	Mat src1, src2;
	src1 = imread("F:\\anh\\toanha.jpg", CV_LOAD_IMAGE_COLOR); // canh nhan tao
	//namedWindow("Original image", CV_WINDOW_AUTOSIZE);
	imshow("anh edge goc", src1);

	Mat gray, edge, draw;
	cvtColor(src1, gray, CV_BGR2GRAY); // chuyen sang anh gray

	Canny(gray, edge, 50, 150, 3); // loc

	edge.convertTo(draw, CV_8U); // chuyen edge sang draw

	//namedWindow("image", CV_WINDOW_AUTOSIZE);
	imshow("anh edge detection 1", draw);

	waitKey(0);
}