#include<stdio.h>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;


void Write_RGB() {
	Mat org = imread("lena.png");//��ɫͼ
	Mat logo_img = imread("logo.png", 0);//�Ҷ�ͼ
	int row = org.rows, col = org.cols;
	resize(logo_img, logo_img, Size(col, row));
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			int x=org.at<Vec3b>(i, j)[0];//0~2 ����BGR 0-B 1-G 2-R
		}
	}
	return;

}
void Read_RGB() {
	return;
}