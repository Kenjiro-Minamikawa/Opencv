#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>

using namespace std;
using namespace cv;

int main(void){
    rs2::pipeline pipe;
    rs2::config cfg;
    cfg.enable_stream(RS2_STREAM_DEPTH);
    cfg.enable_stream(RS2_STREAM_COLOR, 1280, 720, RS2_FORMAT_BGR8, 30);
    pipe.start(cfg);

    rs2::align align_to_color(RS2_STREAM_COLOR);

    while(true){
        rs2::frameset frames = pipe.wait_for_frames();
        rs2::frame color_frame = frames.get_color_frame();

        Mat color(Size(1280,720),CV_8UC3, (void*)color_frame.get_data(), Mat::AUTO_STEP);
        imshow("test", color);

        if(waitKey(10) == 27){
            break;
        }
    }    
    return 0;
}
