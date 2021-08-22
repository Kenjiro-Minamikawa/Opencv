#include <opencv2/opencv.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

#define LOW_HUE		0
#define UP_HUE		10
#define LOW_SATURATION	50
#define LOW_VALUE	50

int main(int argc, char* argv[]){

	const auto window_bf = "before";
	cv::namedWindow(window_bf, CV_WINDOW_AUTOSIZE);
	const auto window_af = "after";
	cv::namedWindow(window_af, CV_WINDOW_AUTOSIZE);

	cv::Mat hsv, frame, hue, hue1, hue2, saturation, value, hue_saturation, image_black_white;

	frame = cv::imread("../media/input.jpg");

	cv::cvtColor(frame, hsv, CV_BGR2HSV, 3);

	std::vector<cv::Mat> singlechannels;

	cv::split(hsv, singlechannels);

	cv::threshold(singlechannels[0], hue1, LOW_HUE, 255, CV_THRESH_BINARY);
	cv::threshold(singlechannels[0], hue2, UP_HUE, 255, CV_THRESH_BINARY_INV);
	cv::threshold(singlechannels[1], saturation, LOW_SATURATION, 255, CV_THRESH_BINARY);
	cv::threshold(singlechannels[2], value, LOW_VALUE, 255, CV_THRESH_BINARY);

	cv::bitwise_and(hue1, hue2, hue);
	cv::bitwise_and(hue, saturation, hue_saturation);

	cv::bitwise_and(hue_saturation, value, image_black_white);

	cv::imshow(window_bf, frame);
	cv::imshow("hsv", hsv);
	cv::imshow(window_af, image_black_white);

	cv::waitKey();

	return 0;
}
