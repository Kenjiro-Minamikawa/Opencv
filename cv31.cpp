#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::VideoCapture cap;
	cap.open(2);

    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FPS, 30);

	if(!cap.isOpened()){
		return -1;
	}

    double gamma = 0.1;

	cv::Mat frame, img;
	while(cap.read(frame)){
    //cv::resize(frame, img, cv::Size(), 0.4, 0.4);
    uchar lut[256];
    for(int i=0; i<256;i++){
        lut[i] = pow(i/255.0, 1/gamma)*255.0;
    }
    cv::LUT(frame, cv::Mat(1, 256, CV_8UC1, lut), img);
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
