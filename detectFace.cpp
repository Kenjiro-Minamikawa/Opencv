#include<opencv2/opencv.hpp>
#include<vector>

using namespace std;
using namespace cv;

int main(){
		CascadeClassifier cascade;
		cascade.load("../haarcascade_frontalface_alt.xml");
		Mat img = imread("../media/lena.jpg", IMREAD_UNCHANGED);
		vector<Rect> faces;
		cascade.detectMultiScale(img, faces, 1.1, 3, 0, Size(20, 20));

		for(int i = 0; i<faces.size(); i++){
			rectangle(img, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AA);
		}

		imshow("detect face", img);
		waitKey();
}
