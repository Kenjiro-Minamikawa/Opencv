#include <ros/ros.h>
#include <cv_bridge/cv_bridge.h>
#include <image_transport/image_transport.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>

int main(int argc, char* argv[]) try {
	ros::init(argc, argv, "img_publish");
	ros::NodeHandle n;
	image_transport::ImageTransport it(n);
	image_transport::Publisher image_pub = it.advertise("image", 10);

	rs2::config cfg;

	cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);

	rs2::pipeline pipe;

	pipe.start(cfg);

	using namespace cv;
	using namespace std;

	ros::Rate looprate(10);

	while(ros::ok()){
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();

		Mat image(Size(640, 480), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);

		sensor_msgs::ImagePtr msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", image).toImageMsg();
		image_pub.publish(msg);
		ros::spinOnce();
		looprate.sleep();
	}

	return EXIT_SUCCESS;
}
catch (const rs2::error & e)
{
    std::cerr << "RealSense error calling " << e.get_failed_function() << "(" << e.get_failed_args() << "):\n    " << e.what() << std::endl;
    return EXIT_FAILURE;
}
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
}
