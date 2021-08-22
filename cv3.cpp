#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat src, dst, img;

	src = cv::imread("../media/image1.png");

	if(src.empty()){
                std::cout << "image was not found!" << std::endl;
                return -1;
        }


	cv::flip(src, dst, 0);
	cv::flip(src, img, 1);

	cv::imshow("反転", dst);
	cv::imshow("対称", img);

	cv::imwrite("../media/反転.png", dst);
	cv::imwrite("../media/対称.png", img);

	cv::waitKey();

	return 0;
}
