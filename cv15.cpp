#include <iostream>
#include <opencv2/opencv.hpp>

#define H_MAX 30
#define H_MIN 0
#define S_MAX 255
#define S_MIN 150
#define V_MAX 255
#define V_MIN 0

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
		
		//cv::Mat input_frame = imread(frame, CV_LOAD_IMAGE_COLOR);

		cv::Mat hsv_frame, mask, output_frame;
		cv::cvtColor(input_frame, hsv_frame, CV_BGR2HSV, 3);

		cv::Scalar s_min = cv::Scalar(H_MIN, S_MIN, V_MIN);
		cv::Scalar s_max = cv::Scalar(H_MAX, S_MAX, V_MAX);
		cv::inRange(hsv_frame, s_min, s_max, mask);

		cv::namedWindow("mask");
		cv::imshow("mask", mask);

		input_frame.copyTo(output_frame, mask);

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
		
