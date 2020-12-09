#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\数图\\头像.png");
	cv::Mat dstMat;
	
	srcMat.convertTo(srcMat, CV_32FC3, 1, 0);//格式转换成float型，以便归一化

	srcMat.copyTo(dstMat);
	
	srcMat = srcMat / 255.0;//图像归一化

	//gamma矫正
	for (int i = 0; i < srcMat.rows; i++)
	{
		for (int j = 0; j < srcMat.cols; j++)
		{
			dstMat.at<Vec3f>(i, j)[0] = pow(srcMat.at<Vec3f>(i, j)[0], 0.5);
			dstMat.at<Vec3f>(i, j)[1] = pow(srcMat.at<Vec3f>(i, j)[1], 0.5);
			dstMat.at<Vec3f>(i, j)[2] = pow(srcMat.at<Vec3f>(i, j)[2], 0.5);

		}

	}
	
	dstMat = dstMat * 255;
	dstMat.convertTo(dstMat, CV_8UC3, 1, 0);

	imshow("原图", srcMat);
	imshow("直方图增强后", dstMat);
	waitKey(0);

}