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
*/
/*
// Creating a blank (light green in this case) image and saving it to file
	Mat blankImage(600, 800, CV_8UC3, Scalar(100, 250, 30));
	String blankWindowName = "Blank Image";
	namedWindow(blankWindowName);
	imshow(blankWindowName, blankImage);

	bool isSuccessBlank = imwrite("/users/iflatinbrovoll/Documents/Bilder/myImage.jpg", blankImage);
	if (isSuccessBlank == false){
		cout << "Failed to save the image" << endl;
	}
	cout << "Image is successfully saved to a file" << endl;

	waitKey(0);
	destroyWindow(blankWindowName);
*/
/*
// Playing a video from file
	VideoCapture cap("/users/iflatinbrovoll/Documents/Bilder/test.avi");
	if (cap.isOpened() == false){
		cout << "Could not open the video file" << endl;
	}

	double fps = cap.get(CAP_PROP_FPS); // Get fps from video
	cout << "Frames per seconds: " << fps << endl;
	cout << "Total number of frames in video: " << cap.get(CAP_PROP_FRAME_COUNT);
	cin.get();

	String windowNameVid = "My first video";
	namedWindow(windowNameVid, WINDOW_NORMAL);

	while (true){
		Mat frame;
		bool bSuccess = cap.read(frame); // Read frame from video

		if (bSuccess == false){ // Breaks while loop if end of video
			cout << "Found the end of the video" << endl;
			break;
		}

		imshow(windowNameVid, frame);

		if (waitKey(30) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}
*/

// Playing a video from the default camera and saving it to file

	VideoCapture capCam(0);
	if (capCam.isOpened() == false){
		cout << "Could not open the video camera" << endl;
	}

	int frameWidth = static_cast<int>(capCam.get(CAP_PROP_FRAME_WIDTH));
	int frameHeight = static_cast<int>(capCam.get(CAP_PROP_FRAME_HEIGHT));

	Size frameSize(frameWidth, frameHeight);
	int fps = 10;

	// M, J, P, G --> Codec for motion JPEG
	VideoWriter oVideoWriter("/users/iflatinbrovoll/Documents/Bilder/myVideo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'),
		fps, frameSize);

	if (oVideoWriter.isOpened() == false){
		cout << "Could not save the video to a file" << endl;
	}

	String windowNameCam = "My camera feed";
	namedWindow(windowNameCam);

	while (true){
		Mat frameCam;
		bool bSuccessCam = capCam.read(frameCam); // Read frame from video

		if (bSuccessCam == false){ // Breaks while loop if end of video
			cout << "Found the end of the video" << endl;
			break;
		}

		oVideoWriter.write(frameCam);

		imshow(windowNameCam, frameCam);

		if (waitKey(10) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}

	return 0;
}


