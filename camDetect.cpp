#include<opencv2/opencv.hpp>
#include<opencv2/aruco.hpp>
#include<string>

int main(int argc, const char** argv){

    /*cv::VideoCapture cap;
    cap.open(0);
    if(!cap.isOpened()){
        return -1;
    }

    if(cap.set(cv::CAP_PROP_FPS, 30.0)){
        return -1;
    }*/
    cv::VideoCapture        cap(0);
        //カメラが開けたか確認
    if(!cap.isOpened())     return -1;
    cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(cv::CAP_PROP_FPS, 30);

    const cv::aruco::PREDEFINED_DICTIONARY_NAME dictionary_name = cv::aruco::DICT_4X4_50;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(dictionary_name);
    std::vector<int> marker_ids;
    std::vector<std::vector<cv::Point2f>> marker_corners;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();

    cv::Mat image;
    float marker_x, marker_y;
    marker_x = 0;
    marker_y = 0;

    while(cap.read(image)){
        cv::aruco::detectMarkers(image, dictionary, marker_corners, marker_ids,  parameters);

        cv::aruco::drawDetectedMarkers(image, marker_corners, marker_ids);
        if(marker_ids.size() > 0){
            for(int i=0; i<marker_ids.size() ;i++){
                marker_x = 0;
                marker_y = 0;
                //std::cout << marker_ids.at(i) << std::endl;
                for(int j=0; j<4; j++){
                    marker_x += marker_corners.at(i).at(j).x;
                    marker_y += marker_corners.at(i).at(j).y;
                }
            marker_x /= 4;
            marker_y /= 4;

            cv::circle(image, cv::Point(marker_x, marker_y), 25, cv::Scalar(0, 200, 0), -1, cv::LINE_AA);
            }
        }
        double fps = cap.get(CV_CAP_PROP_FPS);

        cv::putText(image, std::to_string(fps), cv::Point(50, 50), cv::FONT_HERSHEY_SIMPLEX, 1.5, cv::Scalar(0, 0, 200), 2, CV_AA);
        cv::imshow("detect", image);
        cv::waitKey(1);
    }

    return 0;
}
