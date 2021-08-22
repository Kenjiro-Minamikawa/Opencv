#include<opencv2/opencv.hpp>
#include<iostream>

int main(void){
	cv::VideoCapture cap;
	cap.open(2);
  int px = 902;
  int py = 326;
  int height = 500;
  int width = 500;

    //cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    //cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    //cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    //cap.set(cv::CAP_PROP_FPS, 5);

	if(!cap.isOpened()){
		return -1;
	}

	cv::Mat frame, img;
	while(cap.read(frame)){
    cv::resize(frame, img, cv::Size(), 0.6, 0.6);
    cv::Rect rect = cv::Rect(px, py, height, width);
    cv::Mat img2(img, rect);
		cv::imshow("window", img2);
		const int key = cv::waitKey(1);
		if(key == 'q'){
			break;
		}
		if(key == 'p'){
			cv::imwrite("../media/cam_img.jpg", img);
			std::cout << "captured!" << std::endl;
		}
    if(key == 'w'){
        //std::cout << "up" << std::endl;
        py = py - 10;
        if(py <= 0){
            py = 0;
        }
        //std::cout << img.cols << std::endl;
        //std::cout << img.rows << std::endl;
    }else if(key == 'a'){
        //std::cout << "left" << std::endl;
        px = px - 10;
        if(px <= 10){
            px = 0;
        }
    }else if(key == 'd'){
        //std::cout << "right" << std::endl;
        px = px + 10;
        if(px > img.cols-500){
            px = img.cols - 500;
        }
    }else if(key == 's'){
        //std::cout << "down " << std::endl;
        py = py + 10;
        if(py > img.rows - 500){
            py = img.rows - 500;
        }
    }
	}
	cv::destroyAllWindows();
	return 0;
}
