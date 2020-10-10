#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <string>

int main(int argc, const char* argv[])
{
    // dictionary生成
    const cv::aruco::PREDEFINED_DICTIONARY_NAME dictionary_name = cv::aruco::DICT_4X4_50;
    cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(dictionary_name);

    cv::Mat marker_image;

    // マーカー画像生成
    for(int i=0;i<17;i++){
        int marker_id   = i;
        const int side_pixels = 200;
        cv::aruco::drawMarker(dictionary, marker_id, side_pixels, marker_image);
    // 生成したマーカー画像を表示
        cv::imshow("marker_image", marker_image);
        std::string num = std::to_string(marker_id);
        std::string filename = "../media/"+ num + ".png";
        std::cout << filename << std::endl;
        cv::imwrite(filename, marker_image);
        cv::waitKey(0);
    }

    return 0;
}
