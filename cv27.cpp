#include<iostream>
#include<opencv2/opencv.hpp>

int main(int argc, char *argv[]){
        cv::Mat image, mask, result, gray;
        image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
        if(image.empty()){
                std::cout << "no image" << std::endl;
                return -1;
        }

	cv::cvtColor(image, gray, CV_BGR2GRAY);

	//大津のアルゴリズムを用いて、最適なしきい値を決定している
	cv::threshold(gray, mask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

	std::vector<std::vector<cv::Point> > contours;

	cv::findContours(mask, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	double max_area = 0;
	int max_area_countour = -1;
	
	//std::cout << contours.size() << std::endl;

	for(int i=0; i< contours.size(); i++){
		double area = cv::contourArea(contours.at(i));
		if(max_area<area){
			max_area = area;
			max_area_countour = i;
		}
	}
	//std::cout << max_area_countour << std::endl;
	//cv::Mat cont = cv::Mat(contours.at(max_area_countour));
	std::vector<std::vector<cv::Point> > contours_subset;

	contours_subset.push_back(contours.at(max_area_countour));
	image.copyTo(result, mask);
	cv::Mat cont = cv::Mat(contours_subset.at(0));

	std::vector<cv::Point> approx;

	//周の長さの1%を近似精度としている
	cv::approxPolyDP(cont, approx, 0.01 * cv::arcLength(cont, true), true);

	for(int i=0; i<approx.size(); i++){
		std::cout << approx.at(i) << std::endl;
	}



	cv::drawContours(image, cont, -1, cv::Scalar(0, 255, 0), 4);

	cv::Point2f src[4];

	for(int i=0;i<4;i++){
		src[i] = approx.at(i);
		std::cout << src[i] << std::endl;
	}
		
	cv::Point2f dst[4] = {cv::Point2f(455, 0), cv::Point2f(0, 0), cv::Point2f(0, 275), cv::Point2f(455, 275)};

	cv::Mat perspective_mat = cv::getPerspectiveTransform(src, dst);
	cv::warpPerspective(result, result, perspective_mat, cv::Size(455, 275), cv::INTER_LINEAR);

	cv::namedWindow("src");
	cv::imshow("src", image);
	cv::namedWindow("gray");
	cv::imshow("gray", gray);

	cv::namedWindow("名刺");
	cv::imshow("名刺", result);
	cv::waitKey(0);
	
}


