#include <librealsense2/rs.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

#define H_MAX 30
#define H_MIN 0
#define S_MAX 255
#define S_MIN 150
#define V_MAX 255
#define V_MIN 0

int main(int argc, char* argv[]) try {
	
	rs2::colorizer color_map;
	rs2::config cfg;
	cfg.enable_stream(RS2_STREAM_COLOR, 640, 480, RS2_FORMAT_BGR8, 30);
	cfg.enable_stream(RS2_STREAM_DEPTH, 640, 480, RS2_FORMAT_Z16, 30);
	rs2::pipeline pipe;
	pipe.start(cfg);

	using namespace cv;
	using namespace std;

	const auto color_window = "color";
	namedWindow(color_window, WINDOW_AUTOSIZE);
	const auto depth_window = "depth";
	namedWindow(depth_window, WINDOW_AUTOSIZE);

	while(waitKey(1) > 0){
		rs2::frameset data = pipe.wait_for_frames();
		rs2::align align(RS2_STREAM_COLOR);
		auto aligned_frames = align.process(data);
		rs2::frame color = aligned_frames.get_color_frame();
		rs2::frame depth = aligned_frames.get_depth_frame().apply_filter(color_map);
		rs2::depth_frame dep = aligned_frames.get_depth_frame();

		Mat color_frame(Size(640,480), CV_8UC3, (void*)color.get_data(), Mat::AUTO_STEP);
		Mat depth_frame(Size(640,480), CV_8UC3, (void*)depth.get_data(), Mat::AUTO_STEP);

		Mat hsv_frame, mask_frame, output_frame;

		//二値化
		cvtColor(color_frame, hsv_frame, CV_BGR2HSV, 3);

		namedWindow("HSV");
		imshow("HSV", hsv_frame);
		
		//マスク生成
		Scalar s_min = Scalar(H_MIN, S_MIN, V_MIN);
		Scalar s_max = Scalar(H_MAX, S_MAX, V_MAX);
		inRange(hsv_frame, s_min, s_max, mask_frame);
		morphologyEx(mask_frame, mask_frame, MORPH_ELLIPSE, Mat(), Point(-1, -1), 3);
		erode(mask_frame, mask_frame, Mat(), Point(-1, -1), 3);
		dilate(mask_frame, mask_frame, Mat(), Point(-1, -1), 3);

		color_frame.copyTo(output_frame, mask_frame);

		vector<vector<Point> > contours;

		findContours(mask_frame, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
		if(contours.size() > 0){
			double max_area = 0;
			int max_area_contour = -1;

			for(int i=0;i<contours.size();i++){
				double area=contourArea(contours.at(i));
				if(max_area < area){
					max_area = area;
					max_area_contour = i;
				}
			}

			int count = contours.at(max_area_contour).size();
			double x = 0;
			double y = 0;

			for(int i=0;i<count;i++){
				x+=contours.at(max_area_contour).at(i).x;
				y+=contours.at(max_area_contour).at(i).y;
			}
			x/=count;
			y/=count;

			int px = (int)x;
			int py = (int)y;

			float d = dep.get_distance(px, py);

			cout << "[" << px << "," << py << "," << d << "]" << endl;

			vector<vector<Point> > contours_subset;
			contours_subset.push_back(contours.at(max_area_contour));

			drawContours(output_frame, contours_subset, -1, Scalar(0, 255, 0), -1);

			circle(output_frame, Point(x,y), 5, Scalar(255, 0, 0), -1, -1);

		}


		imshow("mask", mask_frame);
		imshow("output", output_frame);
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

