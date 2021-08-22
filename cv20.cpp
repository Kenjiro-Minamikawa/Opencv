#include <opencv2/opencv.hpp>

int main(int argc, char *argv[]){
	cv::Mat src_img = cv::imread("../media/images.jpeg");
	if(src_img.empty()) return -1;

	cv::Mat dst_img1, dst_img2;

	cv::GaussianBlur(src_img, dst_img1, cv::Size(11,11), 10, 10);
	cv::GaussianBlur(src_img, dst_img2, cv::Size(51,3), 80, 3);
	cv::namedWindow("Blur image1", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Blur image1", dst_img1);
	cv::namedWindow("Blur image2", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
	cv::imshow("Blur image2", dst_img2);

	cv::waitKey(0);

	return 0;
}
