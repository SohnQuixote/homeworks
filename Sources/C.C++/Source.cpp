#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>

#include <iostream>
#include <stdio.h>

#pragma comment(lib,"opencv_core2413d.lib")
#pragma comment(lib,"opencv_objdetect2413d.lib")
#pragma comment(lib,"opencv_highgui2413d.lib")
#pragma comment(lib,"opencv_imgproc2413d.lib")

using namespace std;
using namespace cv;

int main()
{
	VideoCapture cap(0); // open the video camera no. 0

	if (!cap.isOpened())  // if not success, exit program
	{
		cout << "Cannot open the video file" << endl;
		return -1;
	}

	double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Frame size : " << dWidth << " x " << dHeight << endl;

	namedWindow("MyVideo", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	namedWindow("Result", CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	face_cascade.load("C:/opencv/sources/data/haarcascades/haarcascade_frontalface_alt2.xml");

	// Detect faces
	std::vector<Rect> faces;
	

	// Draw circles on the detected faces
	while (1){
		Mat frame, image;

		bool bSuccess = cap.read(frame); // read a new frame from video

		if (!bSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video file" << endl;
			break;
		}

		imshow("MyVideo", frame); //show the frame in "MyVideo" window
		face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));

		for (int i = 0; i < faces.size(); i++)
		{
			Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
			ellipse(frame, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 0), 2, 8, 0);
		}
	}
	imshow("Result", frame);

	waitKey(0);
	return 0;
}
