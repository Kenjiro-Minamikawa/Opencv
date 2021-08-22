#include<iostream>
#include<opencv2/opencv.hpp>

int main(int argc, char *argv[]){
    cv::Mat src1, src2, dst;
  
    src1 = cv::imread("../media/utsu.png");
		src2 = cv::imread("../media/utsu3.png");
    
		if(src1.empty()) return -1;
		if(src2.empty()) return -1;

    cv::Ptr<cv::ORB> orb = cv::ORB::create(25);

    std::vector<cv::KeyPoint> key1, key2;

    orb->detect(src1, key1);
    orb->detect(src2, key2);

		cv::Mat des1, des2;

		orb->compute(src1, key1, des1);
		orb->compute(src2, key2, des2);

		cv::Ptr<cv::DescriptorMatcher> hamming = cv::DescriptorMatcher::create("BruteForce-Hamming");

		std::vector<cv::DMatch> match;
		hamming->match(des1, des2, match);

		cv::drawMatches(src1, key1, src2, key2, match, dst);

    cv::imshow("img1", src1);
    cv::imshow("img2", src2);
    cv::imshow("result", dst);

    cv::waitKey();

    return 0;
}


