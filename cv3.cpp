#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat src, dst, img;

	src = cv::imread("../ロゴ1-1.png");

	cv::flip(src, dst, 0);
	cv::flip(src, img, 1);

	cv::imwrite("./media/反転.png", dst);
	cv::imwrite("./media/対称.png", img);

	cv::waitKey();

	return 0;
}
