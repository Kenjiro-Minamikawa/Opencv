#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::Mat src, dst;

	src = cv::imread("../media/image1.png");

	if(src.empty()){
		std::cout << "image was not found!" << std::endl;
		return -1;
	}

	cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);

	cv::imshow("元画像", src);
	cv::waitKey();
	cv::imshow("変換後", dst);
	cv::waitKey();

	cv::imwrite("../media/変換後.jpg", dst);

	cv::waitKey();

	return 0;
}
