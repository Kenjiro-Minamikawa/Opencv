#include<opencv2/opencv.hpp>
#include<opencv2/aruco.hpp>

int main(int argc, const char** argv){
    cv::Mat image = cv::imread("../media/AR.png");

    const cv::aruco::PREDEFINED_DICTIONARY_NAME dictionary_name = cv::aruco::DICT_4X4_50;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(dictionary_name);
    std::vector<int> marker_ids;
    std::vector<std::vector<cv::Point2f>> marker_corners;
    cv::Ptr<cv::aruco::DetectorParameters> parameters = cv::aruco::DetectorParameters::create();
    cv::aruco::detectMarkers(image, dictionary, marker_corners, marker_ids,  parameters);

    cv::aruco::drawDetectedMarkers(image, marker_corners, marker_ids);
    float marker_x, marker_y;
    for(int i=0; i<marker_ids.size() ;i++){
        marker_x = 0;
        marker_y = 0;
        std::cout << marker_ids.at(i) << std::endl;
        for(int j=0; j<4; j++){
            marker_x += marker_corners.at(i).at(j).x;
            marker_y += marker_corners.at(i).at(j).y;
        }
        marker_x /= 4;
        marker_y /= 4;

        cv::circle(image, cv::Point(marker_x, marker_y), 25, cv::Scalar(0, 200, 0), -1, cv::LINE_AA);
    }
    cv::imshow("detect", image);
    cv::waitKey(0);

    return 0;
}
