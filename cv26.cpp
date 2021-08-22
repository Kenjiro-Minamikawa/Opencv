#include<iostream>
#include<opencv2/opencv.hpp>

#define H_MAX 20
#define H_MIN 0
#define S_MAX 150
#define S_MIN 30
#define V_MAX 255
#define V_MIN 60

using namespace std;

int main(int argc, char *argv[]){
	cv::Mat image;
	image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	if(image.empty()){
		std::cout << "no image" << std::endl;
		return -1;
	}

	cv::Mat hsv, mask, output;

	cv::cvtColor(image, hsv, CV_BGR2HSV);
	
	cv::Scalar s_min = cv::Scalar(H_MIN, S_MIN, V_MIN);
	cv::Scalar s_max = cv::Scalar(H_MAX, S_MAX, V_MAX);

	cv::inRange(hsv, s_min, s_max, mask);

	image.copyTo(output, mask);

	vector<vector<cv::Point> > countours;
	cv::findContours(mask, countours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	double max_area = 0;
	int area_countour = -1;

	for(int j=0;j<countours.size();j++){
		double area = cv::contourArea(countours.at(j));
		if(max_area<area){
			max_area=area;
			area_countour = j;
		}
	}

	vector<vector<cv::Point> > contours_subset;
	contours_subset.push_back(countours.at(area_countour));

	vector<cv::Point> hull;
	cv::convexHull(contours_subset.at(0), hull);
	for(int i=0; i<hull.size(); i++){
		cv::line(output, hull[i], hull[i+1<hull.size()?i+1:0], cv::Scalar(100,100,200), 2, CV_AA);
	}

	cv::drawContours(output, contours_subset, -1, cv::Scalar(0, 255, 0), 4);





	cv::namedWindow("result");
	cv::imshow("result", output);
	cv::waitKey();
}
