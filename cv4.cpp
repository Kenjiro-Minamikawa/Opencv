#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::Mat img, dst;
	img = cv::imread("/home/minamikawa/Opencv/media/rogoimage.png");

	if(img.empty()){
                std::cout << "image was not found!" << std::endl;
                return -1;
        }

	std::cout << img.rows << std::endl << img.cols << std::endl;
	cv::resize(img, dst, cv::Size(), 512.0/img.rows, 512.0/img.cols);
	std::cout << dst.rows << std::endl << dst.cols << std::endl;

	cv::imwrite("/home/minamikawa/Opencv/media/image1.png",dst);

	cv::waitKey();
	
	return 0;
}
