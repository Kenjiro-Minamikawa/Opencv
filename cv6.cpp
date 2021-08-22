#include<iostream>
#include<opencv2/opencv.hpp>

int main(){
	cv::Mat img, dst;

	img = cv::imread("../media/image1.png");
	dst = img.clone();

	cv::circle(dst, cv::Point(255,255), 100, cv::Scalar(255,0,0), 5);
  cv::Rect rect(210, 10, 180, 80);
  cv::rectangle(dst, rect, cv::Scalar(0, 0, 255), 1, cv::LINE_4);

	cv::imshow("input", img);
	cv::imshow("output", dst);

	cv::waitKey();

	return 0;
}
