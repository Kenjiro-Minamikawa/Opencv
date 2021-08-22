#include<opencv2/opencv.hpp>
#include<iostream>

int main(){
    cv::Mat image(400, 400, CV_8UC3);
    image = cv::Scalar(255, 255, 255);

    cv::line(image, cv::Point(10, 10), cv::Point(390, 390), cv::Scalar(255, 0, 0), 1, cv::LINE_4);
    cv::imshow("window", image);
    cv::waitKey();

    return 0;
}
