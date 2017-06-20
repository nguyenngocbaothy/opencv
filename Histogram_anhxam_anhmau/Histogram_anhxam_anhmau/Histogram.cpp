#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	// histogram anh xam
	/*Mat imageSrc = imread("F:\\anh\\lena.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat imageGrayscale;
	int width = 400, height = 400;
	int sizeHistogram = 255;
	float range[] = { 0, 255 };
	const float* histogramRange = { range };

	calcHist(&imageSrc, 1, 0, Mat(), imageGrayscale, 1, &sizeHistogram, &histogramRange, true, false);

	int bin = cvRound((double)width / sizeHistogram);

	Mat dispHistogram(width, height, CV_8UC3, Scalar(255, 255, 255));

	normalize(imageGrayscale, imageGrayscale, 0, dispHistogram.rows, NORM_MINMAX, -1, Mat());

	for (int i = 0; i < 255; i++) {
		line(dispHistogram, Point(bin*(i), height), Point(bin*(i), height - cvRound(imageGrayscale.at<float>(i))), Scalar(0, 0, 0), 2, 8, 0);
	}

	imshow("src", imageSrc);
	imshow("Histogram", dispHistogram);

	waitKey(0);

	return 0;*/


	// histogram anh mau
	Mat imageSrc = imread("F:\\anh\\doremon.jpg", CV_LOAD_IMAGE_COLOR);
	vector<Mat> imageRGB;
	
	Mat imageRed, imageGreen, imageBlue; // bien luu tru 3 kenh mau

	int width = 250, height = 250;
	int sizeHistogram = 255;
	float range[] = { 0, 255 };
	const float* histogramRange = { range };

	split(imageSrc, imageRGB); // tach imageSrc thanh 3 kenh mau

	// tinh toan cho tung kenh mau va ve bieu do Histogram
	calcHist(&imageRGB[0], 1, 0, Mat(), imageRed, 1, &sizeHistogram, &histogramRange, true, false);
	calcHist(&imageRGB[1], 1, 0, Mat(), imageGreen, 1, &sizeHistogram, &histogramRange, true, false);
	calcHist(&imageRGB[2], 1, 0, Mat(), imageBlue, 1, &sizeHistogram, &histogramRange, true, false);

	int bin = cvRound((double)width / sizeHistogram); // chia bin

	Mat dispRed(width, height, CV_8UC3, Scalar(255, 255, 255));
	Mat dispGreen = dispRed.clone();
	Mat dispBlue = dispRed.clone();

	normalize(imageBlue, imageBlue, 0, dispBlue.rows, NORM_MINMAX, -1, Mat());
	normalize(imageGreen, imageGreen, 0, dispGreen.rows, NORM_MINMAX, -1, Mat());
	normalize(imageRed, imageRed, 0, dispRed.rows, NORM_MINMAX, -1, Mat());

	for (int i = 0; i < 255; i++) {
		line(dispRed, Point(bin*(i), height), Point(bin*(i), height - cvRound(imageRed.at<float>(i))), Scalar(0, 0, 255), 2, 8, 0);
		line(dispGreen, Point(bin*(i), height), Point(bin*(i), height - cvRound(imageGreen.at<float>(i))), Scalar(0, 255, 0), 2, 8, 0);
		line(dispBlue, Point(bin*(i), height), Point(bin*(i), height - cvRound(imageBlue.at<float>(i))), Scalar(255, 0, 0), 2, 8, 0);
	}

	namedWindow("src", 0);
	imshow("src", imageSrc);
	imshow("H blue", dispBlue);
	imshow("H green", dispGreen);
	imshow("H red", dispRed);

	waitKey(0);

	return 0;
}