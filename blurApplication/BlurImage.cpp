#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

Mat src, dst;
char windowName1[] = "Unprocessed Image";
char windowName2[] = "Processed Image";

int main(int argc, char** argv){

	src = imread(argv[1], 1);

	namedWindow(windowName1, WINDOW_AUTOSIZE);
	imshow("Unprocessed Image", src);

	dst = src.clone();
	GaussianBlur(src, dst, Size(15, 15), 0, 0);
	imshow("Processed Image", dst);

	waitKey();

	return 0;
}