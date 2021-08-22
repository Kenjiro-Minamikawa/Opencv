#include<opencv2/opencv.hpp>
#include<iostream>

#define H_MAX 20
#define H_MIN 0
#define S_MAX 255
#define S_MIN 150
#define V_MAX 255
#define V_MIN 0

using namespace std;
using namespace cv;

int main(void){
	VideoCapture cap;
	cap.open(2);

	if(!cap.isOpened()){
		cout << "camera is missing!" << endl;
		return -1;
	}
	Mat frame;
	while(cap.read(frame)){
		Mat gray, hsv, o_frame;
		imshow("window", frame);
		cvtColor(frame, hsv, CV_BGR2HSV, 3); 
		//GaussianBlur(gray, gray, Size(9,9), 2, 2);
		
		vector<Vec3f> circles;
		cv::Scalar s_min = cv::Scalar(H_MIN, S_MIN, V_MIN);
        cv::Scalar s_max = cv::Scalar(H_MAX, S_MAX, V_MAX);
        cv::inRange(hsv, s_min, s_max, gray);

        morphologyEx(gray, gray, MORPH_ELLIPSE, Mat(), Point(-1, -1), 3);

        Mat element = Mat::ones(3,3,CV_8UC1);
        Mat mask2;
        erode(gray, gray, element, Point(-1,-1), 5);
        //dilate(gray, gray, element, Point(-1,-1), 4);

        cv::namedWindow("mask");
        cv::imshow("mask", gray);
		HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 3, gray.rows/4, 200, 100);
		for(size_t i=0;i<circles.size();i++){
			Point center(cvRound(circles[i][0]),cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			circle(frame, center, 3, Scalar(0,255,0), -1, 8, 0);
			circle(frame, center, radius, Scalar(0,0,255), 3, 8, 0);
		}
		frame.copyTo(o_frame, gray);
		imshow("frame", o_frame);
		imshow("gray", gray);
		const int key = cv::waitKey(1);
		if(key == 'q'){
			break;
		}
	}
	cv::destroyAllWindows();
	return 0;
}
