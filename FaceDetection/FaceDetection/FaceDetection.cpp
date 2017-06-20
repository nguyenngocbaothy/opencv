#include "opencv2/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/objdetect.hpp" // nho load thu vien
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
	Mat image = imread("family2.jpg", CV_LOAD_IMAGE_COLOR);

	namedWindow("window1", 1);   imshow("window1", image);

	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	CascadeClassifier eyes_cascade;
	face_cascade.load("F:\\opencv 3.0\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml");

	// Detect faces
	vector<Rect> faces;
	face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

	//void CascadeClassifier::detectMultiScale(const Mat& image, vector<Rect>& objects, double scaleFactor = 1.1, int minNeighbors = 3, int flags = 0, Size minSize = Size(), Size maxSize = Size())
	// Detects objects of different sizes in the input image. 
	// The detected objects are returned as a list of rectangles.

	// Draw circles on the detected faces
	for (int i = 0; i < faces.size(); i++)
	{
		Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
		ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
	}

	imshow("Detected Face", image);

	waitKey(0);
	return 0;
}