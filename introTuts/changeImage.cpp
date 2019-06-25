#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;


int main(int argc, char** argv){

	Mat imageWhale = imread("/users/iflatinbrovoll/Documents/Bilder/whale.png");
	if (imageWhale.empty()){
		cout << "Could not open file or find the image" << endl;
		return -1;
	}

	Mat imageBrightnessHigh50;
	imageWhale.convertTo(imageBrightnessHigh50, -1, -1, 50);

	Mat imageBrightnessHigh100;
	imageWhale.convertTo(imageBrightnessHigh50, -1, -1, 100);

	Mat imageBrightnessLow50;
	imageWhale.convertTo(imageBrightnessLow50, -1, -1, 50);

	Mat imageBrightnessLow100;
	imageWhale.convertTo(imageBrightnessLow50, -1, -1, 100);

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

	imshow(windowNameOriginalImage, imageWhale);
	imshow(windowNameBrightnessHigh50, imageBrightnessHigh50);
	imshow(windowNameBrightnessHigh100, imageBrightnessHigh100);
	imshow(windowNameBrightnessLow50, imageBrightnessLow50);
	imshow(windowNameBrightnessLow100, imageBrightnessLow100);

	waitKey(0);

	return 0;
}








