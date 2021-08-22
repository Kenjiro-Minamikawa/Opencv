#include <opencv2/core/core.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main( int argc, char** argv )
{
    std::cout << cv::getBuildInformation() << std::endl;
    return 0;
}
