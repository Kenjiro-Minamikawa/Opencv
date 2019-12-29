#include <iostream>
#include <opencv2/opencv.hpp>

#define H_MAX 30
#define H_MIN 0
#define S_MAX 255
#define S_MIN 150
#define V_MAX 255
#define V_MIN 100

using namespace cv;
using namespace std;

int main(int argc, char* argv[]){
	cv::VideoCapture cap;
	cap.open(0);

	if(!cap.isOpened()){
		std::cerr << "ERROE:There was no camera!" << std::endl;
	}

	cv::Mat input_frame;
	while(cap.read(input_frame)){
		cv::namedWindow("before");
		cv::imshow("before", input_frame);

		cv::Mat hsv_frame, mask, output_frame;
		cv::cvtColor(input_frame, hsv_frame, CV_BGR2HSV, 3);

		cv::Scalar s_min = cv::Scalar(H_MIN, S_MIN, V_MIN);
		cv::Scalar s_max = cv::Scalar(H_MAX, S_MAX, V_MAX);
		cv::inRange(hsv_frame, s_min, s_max, mask);

		morphologyEx(mask, mask, MORPH_ELLIPSE, Mat(), Point(-1, -1), 3);

		Mat element = Mat::ones(3,3,CV_8UC1);
		Mat mask2;
		erode(mask, mask2, element, Point(-1,-1), 3);
		dilate(mask2, mask2, element, Point(-1,-1), 3);

		input_frame.copyTo(output_frame, mask2);

		cv::namedWindow("mask");
		cv::imshow("mask", mask2);

		vector<vector<cv::Point> > contours;
		findContours(mask2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

		double max_area=0;
		int max_area_contour=-1;

		for(int j=0;j<contours.size();j++){
			double area=contourArea(contours.at(j));
			if(max_area<area){
				max_area = area;
				max_area_contour = j;
			}
		}

		int count=contours.at(max_area_contour).size();
		double x=0;
		double y=0;

		for(int k=0;k<count;k++){
			x+=contours.at(max_area_contour).at(k).x;
			y+=contours.at(max_area_contour).at(k).y;
		}

		x/=count;
		y/=count;

		vector<vector<Point> > contours_subset;
		contours_subset.push_back(contours.at(max_area_contour));

		drawContours(output_frame, contours_subset, -1, Scalar(0,255,0), -1);

		circle(output_frame, Point(x,y), 100, Scalar(255,0,0), 3, 4);

		cv::namedWindow("after");
		cv::imshow("after", output_frame);

		const int key = cv::waitKey(1);
		if(key == 'q'){
			break;
		}
	}
	cv::destroyAllWindows();
	return 0;
}

