#include<opencv2/opencv.hpp>

int main(void){
	cv::VideoCapture cap;
	cap.open(0);

	if(!cap.isOpened()){
		return -1;
	}

	cv::Mat frame;
	while(cap.read(frame)){
		cv::imshow("window", frame);
		const int key = cv::waitKey(1);
		if(key == 'q'){
			break;
		}
	}
	cv::destroyAllWindows();
	return 0;
}
