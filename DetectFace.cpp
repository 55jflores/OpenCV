#include <opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat detectFaces(Mat img, CascadeClassifier faceCascade) {
	
	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	Mat blurred_region;
	//Iterate through detected faces
	for (int i = 0; i < faces.size(); i++) {

		// Black out the face
		img(faces[i]).setTo(0);

		// Blur out the face
		//GaussianBlur(img(faces[i]), blurred_region, Size(45, 45), 0, 0);
		//blurred_region.copyTo(img(faces[i]));

		// Draw rectangle around face
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 255, 0), 3);

	}
	return img;
}


int main() {
	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");
	if (faceCascade.empty()) {
		cout << "File not loaded" << endl;
	}

	VideoCapture cap(0);
	// Holds individual frame from capture
	Mat frame;
	char pressed_esc = 0;

	while (pressed_esc != 27) {

		// Grabbing individual frame
		cap >> frame;

		// If frame is emtpy break
		if (frame.empty()) {
			break;
		}

		frame = detectFaces(frame, faceCascade);
		// Show frame after going through cascade classifier
		imshow("Frame", frame);

		// If you press on escape key
		pressed_esc = waitKey(1);
	}

	cap.release();
	destroyAllWindows();

	return 0;
}

