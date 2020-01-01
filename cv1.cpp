#include<iostream>
#include<opencv2/opencv.hpp>

int main(void){
	cv::Mat image;
	image = cv::imread("/home/minamikawa/Opencv/media/rogoimage.png");
	if(image.empty()){
		std::cout << "image was not found!" << std::endl;
	       	return -1;
	}
	cv::namedWindow("mado");

	cv::imshow("mado", image);

	cv::waitKey();

	return 0;
}
