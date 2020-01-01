#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

// 抽出する画像の輝度値の範囲を指定
#define H_MAX 180
#define H_MIN 160
#define S_MAX 255
#define S_MIN 50
#define V_MAX 255
#define V_MIN 50

// メイン関数
int main(void)
{
	// 入力画像名(ファイルパス)
	string input_filename = "/home/minamikawa/Opencv/media/input.jpg";

	// 画像を3チャンネル(BGR)で読み込む
	Mat input_image_rgb = imread(input_filename, CV_LOAD_IMAGE_COLOR);
	if (input_image_rgb.empty()) {
		cerr << "入力画像が見つかりません" << endl;
		return -1;
	}

	// 表示して確認
	namedWindow("input_RGB");
	imshow("input_RGB", input_image_rgb);

	// BGRからHSVへ変換
	Mat hsv_image, mask_image, output_image;
	cvtColor(input_image_rgb, hsv_image, CV_BGR2HSV, 3);

	// HSV変換した画像を表示して確認
	namedWindow("input_HSV");
	imshow("input_HSV", hsv_image);
	imwrite("/home/minamikawa/Opencv/media/hsv.jpg", hsv_image);

	// inRangeを用いてフィルタリング
	Scalar s_min = Scalar(H_MIN, S_MIN, V_MIN);
	Scalar s_max = Scalar(H_MAX, S_MAX, V_MAX);
	inRange(hsv_image, s_min, s_max, mask_image);

	// マスク画像を表示
	namedWindow("mask");
	imshow("mask", mask_image);
	imwrite("/home/minamikawa/Opencv/media/mask.jpg", mask_image);

	Mat element = Mat::ones(3,3,CV_8UC1);
        Mat mask2;
        dilate(mask_image, mask2, element, Point(-1,-1), 1);

	imshow("mask2", mask2);

	// マスクを基に入力画像をフィルタリング
	input_image_rgb.copyTo(output_image, mask2);

	vector<vector<Point> > contours;
	findContours(mask2, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	double max_area=0;
	int max_area_contour=-1;

	for(int j=0;j<contours.size();j++){
		double area=contourArea(contours.at(j));
		if(max_area<area){
			max_area = area;
			max_area_contour = j;
		}
	}

	int count=contours.at(max_area_contour).size();
	double x=0;
	double y=0;

	for(int k=0;k<count;k++){
		x+=contours.at(max_area_contour).at(k).x;
		y+=contours.at(max_area_contour).at(k).y;
	}

	x/=count;
	y/=count;

	vector<vector<Point> > contours_subset;
	contours_subset.push_back(contours.at(max_area_contour));

	drawContours(output_image, contours_subset, -1, Scalar(0,255,0), -1);

	circle(output_image, Point(x,y), 100, Scalar(255,0,0), 3, 4);
	
	// 結果の表示と保存
	namedWindow("output");
	imshow("output", output_image);
	imwrite("/home/minamikawa/Opencv/media/output.jpg", output_image);
	waitKey(0);

	return 0;
}
