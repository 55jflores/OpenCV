#include "opencv2\opencv.hpp"
#include "opencv2\highgui.hpp"
#include <vector>
using namespace std;
using namespace cv;

int main() {

	Mat myImage;
	myImage = imread("C:\\Users\\jesus\\Desktop\\mytorch\\dog.jpg");
	
	Mat test = imread("C:\\Users\\jesus\\Desktop\\mytorch\\dog.jpg");
	test = Scalar::all(0);
	
	vector<Mat> bgr;
	split(myImage, bgr);

	vector<Mat>bgr2;
	split(test, bgr2);
	
	// Blue color
	bgr2[0] = bgr[0]
	// Green color
	// bgr2[1] = bgr[1];

	// Red color
	// bgr2[2] = bgr[2];

	Mat newpic;
	vector<Mat> channels = { bgr2[0],bgr2[1] ,bgr2[2] };
	merge(channels,newpic);
	
	imshow("Pic", newpic);

	waitKey(0);
	destroyAllWindows();

	return 0;

}