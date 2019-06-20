#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

/*
// Loading and displaying an image from file
	Mat image = imread("/users/iflatinbrovoll/Documents/Bilder/whale.png");
	if (image.empty()){
		cout << "Could not open or find the image" << endl;
		return -1;
	}

	String windowName = "The whale";
	namedWindow(windowName);
	imshow(windowName, image);

	waitKey(0);
	destroyWindow(windowName);


// Creating a blank (light green in this case) image
	Mat blankImage(600, 800, CV_8UC3, Scalar(100, 250, 30));
	String blankWindowName = "Blank Image";
	namedWindow(blankWindowName);
	imshow(blankWindowName, blankImage);

	waitKey(0);
	destroyWindow(blankWindowName);


// Playing a video from file
	VideoCapture cap("/users/iflatinbrovoll/Documents/Bilder/test.avi");
	if (cap.isOpened() == false){
		cout << "Could not open the video file" << endl;
	}

	double fps = cap.get(CAP_PROP_FPS); // Get fps from video
	cout << "Frames per seconds: " << fps << endl;
	cout << "Total number of frames in video: " << cap.get(CAP_PROP_FRAME_COUNT);
	cin.get();

	String windowName = "My first video";
	namedWindow(windowName, WINDOW_NORMAL);

	while (true){
		Mat frame;
		bool bSuccess = cap.read(frame); // Read frame from video

		if (bSuccess == false){ // Breaks while loop if end of video
			cout << "Found the end of the video" << endl;
			break;
		}

		imshow(windowName, frame);

		if (waitKey(30) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}

*/
// Playing a video from the default camera

	VideoCapture cap(0);
	if (cap.isOpened() == false){
		cout << "Could not open the video camera" << endl;
	}

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH);
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT);
	cout << "Resolution of the video: " << dWidth << " x " << dHeight << endl;

	String windowNameCam = "My camera feed";
	namedWindow(windowNameCam, WINDOW_NORMAL);

	while (true){
		Mat frameCam;
		bool bSuccessCam = cap.read(frameCam); // Read frame from video

		if (bSuccessCam == false){ // Breaks while loop if end of video
			cout << "Found the end of the video" << endl;
			break;
		}

		imshow(windowNameCam, frameCam);

		if (waitKey(10) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}

	return 0;
}


