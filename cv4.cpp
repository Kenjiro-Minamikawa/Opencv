#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::Mat img, dst;
	img = cv::imread("../ロゴ1-1.png");

	std::cout << img.rows << std::endl << img.cols << std::endl;
	cv::resize(img, dst, cv::Size(), 512.0/img.rows, 512.0/img.cols);
	std::cout << dst.rows << std::endl << dst.cols << std::endl;

	cv::imwrite("./image1.png",dst);

	cv::waitKey();
	
	return 0;
}
