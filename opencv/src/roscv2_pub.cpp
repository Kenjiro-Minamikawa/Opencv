#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv){
	ros::init(argc, argv, "img_pub");
	ros::NodeHandle n;
	image_transport::ImageTransport it(n);
	image_transport::Publisher image_pub = it.advertise("image", 10);
	cv::Mat image;
	image = cv::imread("/home/minamikawa/Opencv/media/image1.png");
	if(image.empty()){
                std::cout << "image was not found!" << std::endl;
                return -1;
        }
	ros::Rate looprate(10);

	while(ros::ok()){
		sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
		image_pub.publish(msg);
		ros::spinOnce();
		looprate.sleep();
	}

	return 0;
}
