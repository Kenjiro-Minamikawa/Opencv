#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat img;

	img = cv::imread("../ロゴ1-1.png");

	cv::Rect rect = cv::Rect(4000,4000, 300, 300);
	cv::Mat src(img, rect);
	cv::imshow("", src);
	cv::waitKey();
	return 0;
}
