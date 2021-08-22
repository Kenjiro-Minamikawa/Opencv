#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::VideoCapture cap;
	cap.open(0);

    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FPS, 5);

	if(!cap.isOpened()){
		return -1;
	}

	cv::Mat frame, img;
	while(cap.read(frame)){
    cv::resize(frame, img, cv::Size(), 0.4, 0.4);
		cv::imshow("window", img);
		const int key = cv::waitKey(1);
		if(key == 'q'){
			break;
		}
		if(key == 'p'){
			cv::imwrite("../media/cam_img.jpg", img);
			std::cout << "captured!" << std::endl;
		}
	}
	cv::destroyAllWindows();
	return 0;
}
