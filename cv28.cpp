#include<iostream>
#include<opencv2/opencv.hpp>

int main(int argc, char *argv[]){
        cv::Mat src_img;
        src_img = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        if(src_img.empty()){
                std::cout << "no image" << std::endl;
                return -1;
        }
	
	cv::Point2f pts1[] = {cv::Point2f(150, 150), cv::Point2f(150, 300), cv::Point2f(350, 300), cv::Point2f(350, 150)};
	cv::Point2f pts2[] = {cv::Point2f(200, 150), cv::Point2f(200, 300), cv::Point2f(340, 270), cv::Point2f(340, 180)};

	cv::Mat perspective_mat = cv::getPerspectiveTransform(pts1, pts2);
	cv::Mat dst_img;

	cv::warpPerspective(src_img, dst_img, perspective_mat, src_img.size(), cv::INTER_LINEAR);
	
	cv::namedWindow("src");
	cv::namedWindow("dst");
	cv::imshow("src", src_img);
	cv::imshow("dst", dst_img);
	cv::waitKey(0);
}
