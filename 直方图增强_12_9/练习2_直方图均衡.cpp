#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\lena.png");
	cv::Mat dstMat;

	std::vector<cv::Mat> channels_1;
	
	split(srcMat, channels_1);//通道分离

	cv::Mat srcB = channels_1.at(0);
	cv::Mat srcG = channels_1.at(1);
	cv::Mat srcR = channels_1.at(2);

	//直方图均衡
	equalizeHist(srcB, srcB);
	equalizeHist(srcG, srcG);
	equalizeHist(srcR, srcR);

	merge(channels_1, dstMat);//通道合并

	imshow("原图", srcMat);
	imshow("直方图均衡", dstMat);
	waitKey(0);


}