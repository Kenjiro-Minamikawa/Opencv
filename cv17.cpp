#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;

// 抽出する画像の輝度値の範囲を指定
#define B_MAX 100
#define B_MIN 0
#define G_MAX 100
#define G_MIN 0
#define R_MAX 255
#define R_MIN 100

// メイン関数
int main(void)
{
	// 入力画像名(ファイルパス)
	string input_filename = "../media/block.png";

	// 画像を3チャンネル(BGR)で読み込む
	Mat input_image_rgb = imread(input_filename, CV_LOAD_IMAGE_COLOR);
	if (input_image_rgb.empty()) {
		cerr << "入力画像が見つかりません" << endl;
		return -1;
	}

	// 表示して確認
	namedWindow("input_RGB");
	imshow("input_RGB", input_image_rgb);

	// 結果保存用Matを定義
	Mat mask_image, output_image_rgb;

	// inRangeを用いてフィルタリング
	Scalar s_min = Scalar(B_MIN, G_MIN, R_MIN);
	Scalar s_max = Scalar(B_MAX, G_MAX, R_MAX);
	inRange(input_image_rgb, s_min, s_max, mask_image);

	// マスク画像を表示
	namedWindow("mask");
	imshow("mask", mask_image);
	imwrite("../media/mask.jpg", mask_image);

	vector<vector<Point> > countours;
	findContours(mask_image, countours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);

	double max_area=0;
	int max_area_countour=-1;

	for(int j=0;j<countours.size();j++){
		double area=contourArea(countours.at(j));
		if(max_area<area){
			max_area=area;
			max_area_countour=j;
		}
	}

	int count=countours.at(max_area_countour).size();
	double x=0;
	double y=0;

	for(int k=0;k<count;k++){
		x+=countours.at(max_area_countour).at(k).x;
		y+=countours.at(max_area_countour).at(k).y;
	}

	x/=count;
	y/=count;

	vector<vector<Point> > contours_subset;
	contours_subset.push_back(countours.at(max_area_countour));

	// マスクを基に入力画像をフィルタリング
	input_image_rgb.copyTo(output_image_rgb, mask_image);

	drawContours(output_image_rgb, contours_subset,-1,Scalar(0,255,0), 4);

	circle(output_image_rgb, Point(x,y), 100, Scalar(255,0,0), 3, 4);

	// 結果の表示と保存
	namedWindow("output");
	imshow("output", output_image_rgb);
	imwrite("../media/output.jpg", output_image_rgb);
	waitKey(0);

	return 0;
}
