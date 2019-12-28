#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>

int main(int argc, char* argv[]) try {
	
	rs2::colorizer color_map;
	rs2::config cfg;
	cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);
	cfg.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
	rs2::pipeline pipe;
	pipe.start(cfg);

	using namespace cv;

	const auto color_window = "color";
	namedWindow(color_window, WINDOW_AUTOSIZE);
	const auto depth_window = "depth";
	namedWindow(depth_window, WINDOW_AUTOSIZE);

	while(waitKey(1) > 0){
		rs2::frameset data = pipe.wait_for_frames();
		rs2::frame color = data.get_color_frame();
		rs2::frame depth = data.get_depth_frame().apply_filter(color_map);

		Mat color_frame(Size(640,480), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
		Mat depth_frame(Size(640,480), CV_8UC3, (void*)depth.get_data(), Mat::AUTO_STEP);

		imshow(color_window, color_frame);
		imshow(depth_window, depth_frame);
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

