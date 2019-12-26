#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat src, dst;

	src = cv::imread("../ロゴ1-1.png");

	cv::cvtColor(src, dst, cv::COLOR_BGR2GRAY);

	cv::imshow("元画像", src);
	cv::waitKey();
	cv::imshow("変換後", dst);
	cv::waitKey();

	cv::imwrite("./media/変換後.jpg", dst);

	cv::waitKey();

	return 0;
}
