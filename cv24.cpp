#include<iostream>
#include<opencv2/opencv.hpp>

int main(int argc, char *argv[]){
		cv::Mat src, dstAkaze, dstOrb, dstSurf;
	
		src = cv::imread("../media/utsu.png");
		if(src.empty()) return -1;

		cv::Ptr<cv::AKAZE> akaze = cv::AKAZE::create(cv::AKAZE::DESCRIPTOR_MLDB, 0, 3, 0.01f);
		cv::Ptr<cv::ORB> orb = cv::ORB::create(500, 1.2f, 2);

		std::vector<cv::KeyPoint> keyAkaze, keyOrb, keySurf;

		akaze->detect(src, keyAkaze);
		orb->detect(src, keyOrb);

		cv::drawKeypoints(src, keyAkaze, dstAkaze, cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
		cv::drawKeypoints(src, keyOrb,   dstOrb,   cv::Scalar::all(-1), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);

		cv::imshow("origin", src);
		cv::imshow("AKAZE", dstAkaze);
		cv::imshow("ORB", dstOrb);

		cv::waitKey();

		return 0;
}

