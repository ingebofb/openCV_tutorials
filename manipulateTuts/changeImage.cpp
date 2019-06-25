#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

/* 
Changing brightness: Add or subtract a constant for each pixel
Changing contrast: Multiply each pixel by a pos constant > 1 to increase and 0 < c < 1 to decrease
*/

const int intensitySlider_max = 10;
int sliderValue = 1;

Mat src1;
Mat dst;

void onTrackbar(int, void*){

	dst = src1/sliderValue;
	imshow("Intensity Change", dst);
}


int main(int argc, char** argv){

	src1 = imread("/users/iflatinbrovoll/Documents/Bilder/whale.png");

	if (src1.empty()) {cout << "Error loading src1\n"; return -1;}

	namedWindow("Intensity Change", 1);
	namedWindow("Original Image", WINDOW_AUTOSIZE);
	
	imshow("Original Image", src1);

	createTrackbar("Intensity", "Intensity Change", &sliderValue, intensitySlider_max, onTrackbar);

	onTrackbar(sliderValue, 0);

	waitKey(0);


	Mat imageWhale = imread("/users/iflatinbrovoll/Documents/Bilder/whale.png");
	if (imageWhale.empty()){
		cout << "Could not open file or find the image" << endl;
		return -1;
	}

// Changing brightness of image from file
/*	Mat imageBrightnessHigh50;
	imageWhale.convertTo(imageBrightnessHigh50, -1, 1, 50); // ouput_pixel = input_pixel*1 + 50
	// -1 in second argument means same type in output image as in input image
	Mat imageBrightnessHigh100;
	imageWhale.convertTo(imageBrightnessHigh100, -1, 1, 100); // ouput_pixel = input_pixel*1 + 100

	Mat imageBrightnessLow50;
	imageWhale.convertTo(imageBrightnessLow50, -1, 1, -50); // ouput_pixel = input_pixel*1 - 50

	Mat imageBrightnessLow100;
	imageWhale.convertTo(imageBrightnessLow100, -1, 1, -100); // ouput_pixel = input_pixel*1 - 100

	String windowNameOriginalImage = "Original Image";
	String windowNameBrightnessHigh50 = "Brightness Increased by 50";
	String windowNameBrightnessHigh100 = "Brightness Increased by 100";
	String windowNameBrightnessLow50 = "Brightness Decreased by 50";
	String windowNameBrightnessLow100 = "Brightness Decreased by 100";

	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh100, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

	// TEST
	cout << (int)imageWhale.at<Vec3b>(0,0)[0] << endl;
	cout << (int)imageBrightnessHigh50.at<Vec3b>(0,0)[0] << endl;
	cout << (int)imageBrightnessHigh100.at<Vec3b>(0,0)[0] << endl;

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameBrightnessHigh50, imageBrightnessHigh50);
	imshow(windowNameBrightnessHigh100, imageBrightnessHigh100);
	imshow(windowNameBrightnessLow50, imageBrightnessLow50);
	imshow(windowNameBrightnessLow100, imageBrightnessLow100);

	waitKey(0);
	destroyAllWindows();
*/

	// Changing contrast of image from file
/*	Mat imageContrastChange;
	imageWhale.convertTo(imageContrastChange, -1, 1.5, 0);

	String windowNameOriginalImage = "Original Image";
	String windowNameContrastChanged = "Contrast Changed";

	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameContrastChanged, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameContrastChanged, imageContrastChange);

	waitKey(0);
	destroyAllWindows();
*/

	// Histogram equalization of a grayscale image
/*	cvtColor(imageWhale, imageWhale, COLOR_BGR2GRAY);

	Mat hist_equalized_image;
	equalizeHist(imageWhale, hist_equalized_image);

	String windowNameOriginalImage = "Original Image";
	String windowNameHistogramEqualized = "Histogram Equalized Image";

	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameHistogramEqualized, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameHistogramEqualized, hist_equalized_image);

	waitKey(0);
	destroyAllWindows();
*/

	// Histogram equalization of a color image
/*	Mat hist_equalized_image;
	cvtColor(imageWhale, hist_equalized_image, COLOR_BGR2YCrCb);

	vector<Mat> vec_channels;
	split(hist_equalized_image, vec_channels);

	equalizeHist(vec_channels[0], vec_channels[0]);

	merge(vec_channels, hist_equalized_image);

	cvtColor(hist_equalized_image, hist_equalized_image, COLOR_YCrCb2BGR);

	String windowNameOriginalImage = "Original Image";
	String windowNameHistogramEqualized = "Histogram Equalized Color Image";

	namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
	namedWindow(windowNameHistogramEqualized, WINDOW_NORMAL);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameHistogramEqualized, hist_equalized_image);

	waitKey(0);
	destroyAllWindows();
*/

	// Homogenous blur on image
/*	Mat imageBlurred;
	blur(imageWhale, imageBlurred, Size(5, 5));

	String windowNameOriginalImage = "Original Image";
	String windowNameBlurredImage = "Blurred Image";

	namedWindow(windowNameOriginalImage);
	namedWindow(windowNameBlurredImage);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameBlurredImage, imageBlurred);

	waitKey(0);
	destroyAllWindows();
*/

	// Gaussian blur on image
/*	Mat imageGaussianBlurred;
	GaussianBlur(imageWhale, imageGaussianBlurred, Size(3, 3), 0);

	String windowNameOriginalImage = "Original Image";
	String windowNameGaussianBlurred = "Blurred Image";

	namedWindow(windowNameOriginalImage);
	namedWindow(windowNameGaussianBlurred);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameGaussianBlurred, imageGaussianBlurred);

	waitKey(0);
	destroyAllWindows();
*/

	// Erode image
/*	Mat imageEroded;
	erode(imageWhale, imageEroded, getStructuringElement(MORPH_RECT, Size(3, 3)));

	String windowNameOriginalImage = "Original Image";
	String windowNameEroded = "Eroded Image";

	namedWindow(windowNameOriginalImage);
	namedWindow(windowNameEroded);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameEroded, imageEroded);

	waitKey(0);
	destroyAllWindows();
*/

	// Dilate image
/*	Mat imageDilated;
	dilate(imageWhale, imageDilated, getStructuringElement(MORPH_RECT, Size(3, 3)));

	String windowNameOriginalImage = "Original Image";
	String windowNameDilated = "Dilated Image";

	namedWindow(windowNameOriginalImage);
	namedWindow(windowNameDilated);

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameDilated, imageDilated);

	waitKey(0);
	destroyAllWindows();
*/

	VideoCapture cap("/users/iflatinbrovoll/Documents/Bilder/test.AVI");
	if (cap.isOpened() == false){
		cout << "Cannot open the video file" << endl;
		return -1;
	}

// Changing brightness of video from file
/*	String windowNameOriginalVideo = "Original Video";
	String windowNameBrightnessHigh50Vid = "Brightness Increased by 50";
	String windowNameBrightnessHigh100Vid = "Brightness Increased by 100";
	String windowNameBrightnessLow50Vid = "Brightness Decreased by 50";
	String windowNameBrightnessLow100Vid = "Brightness Decreased by 100";

	namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh50Vid, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessHigh100Vid, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow50Vid, WINDOW_NORMAL);
	namedWindow(windowNameBrightnessLow100Vid, WINDOW_NORMAL);

	while (true){
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false){
			cout << "Found the end of the video" << endl;
			break;
		}

		Mat frameBrightnessHigh50;
		frame.convertTo(frameBrightnessHigh50, -1, 1, 50);

		Mat frameBrightnessHigh100;
		frame.convertTo(frameBrightnessHigh100, -1, 1, 100);

		Mat frameBrightnessLow50;
		frame.convertTo(frameBrightnessLow50, -1, 1, -50);

		Mat frameBrightnessLow100;
		frame.convertTo(frameBrightnessLow100, -1, 1, -100);

		imshow(windowNameOriginalVideo, frame);
		imshow(windowNameBrightnessHigh50Vid, frameBrightnessHigh50);
		imshow(windowNameBrightnessHigh100Vid, frameBrightnessHigh100);
		imshow(windowNameBrightnessLow50Vid, frameBrightnessLow50);
		imshow(windowNameBrightnessLow100Vid, frameBrightnessLow100);

		if (waitKey(50) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}
*/

	// Changing contrast of video from file
/*	String windowNameOriginalVideo = "Original Image";
	String windowNameContrastChangedVid = "Contrast changed";

	namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
	namedWindow(windowNameContrastChangedVid, WINDOW_NORMAL);

	while (true){
		Mat frame;
		bool bSuccess = cap.read(frame);

		if (bSuccess == false){
			cout << "Found the end of the video" << endl;
			break;
		}

		Mat frameContrastChangedVid;
		frame.convertTo(frameContrastChangedVid, -1, 1.5, 0);

		imshow(windowNameOriginalVideo, frame);
		imshow(windowNameContrastChangedVid, frameContrastChangedVid);

		if (waitKey(50) == 27){
			cout << "Esc key is pressed by user. Stopping the video" << endl;
			break;
		}
	}
*/
	return 0;
}








