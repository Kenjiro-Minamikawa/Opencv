#include<iostream>
#include<opencv2/opencv.hpp>

int main(){
	cv::Mat img, dst;

	img = cv::imread("/home/minamikawa/Opencv/media/image1.png");
	dst = img.clone();

	cv::circle(dst, cv::Point(255,255), 100, cv::Scalar(255,0,0), 5);

	cv::imshow("input", img);
	cv::imshow("output", dst);

	cv::waitKey();

	return 0;
}
