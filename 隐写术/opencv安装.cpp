#include<stdio.h>
#include<opencv2/opencv.hpp>
using namespace cv;
using namespace std;
#include"RGB.cpp"
/// <summary>
/// LSB信息隐藏算法
/// </summary>
/// <param name="name"></param>
void read(string name) {
	Mat org = imread(name, 0);
	int row = org.rows, col = org.cols;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			org.at<uchar>(i, j) &= 1;
			org.at<uchar>(i, j) *= 255;
		}
	}
	imshow("结果",org);
	waitKey(0);
}
Mat write(string orgname,string logoname) {
	Mat org = imread(orgname,0);
	Mat logo = imread(logoname,0);

	int rowcount = org.rows;
	int colcount = org.cols;
	resize(logo, logo, Size(colcount, rowcount));//重新调整大小
	for (int i = 0; i < rowcount; i++) {
		for (int j = 0; j < colcount; j++) {
			int t = org.at<uchar>(i, j);
			int x = logo.at<uchar>(i, j) >127;
			//printf("%d", x);
			if ((t & 1) != x) org.at<uchar>(i, j) ^= 1;
		}
		
		cout << endl;
	}
	return org;
	
}
int main() {

	/*read("steg.png");
	Mat s=write("lena.png", "logo.png");
	imwrite("s.png", s);*/
	Write_RGB();
	Read_RGB();

	
	
	return 0;
}