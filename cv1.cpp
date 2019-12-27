#include<iostream>
#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat image;
	image = cv::imread("rogoimage.png");
	if(image.empty()) return -1;

	cv::namedWindow("mado");

	cv::imshow("mado", image);

	cv::waitKey();

	return 0;
}
