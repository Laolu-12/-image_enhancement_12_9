#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

int main()
{
	cv::Mat srcMat = imread("C:\\Users\\Lenovo\\Pictures\\��ͼ\\ͷ��.png");
	cv::Mat dstMat;
	
	srcMat.convertTo(srcMat, CV_32FC3, 1, 0);//��ʽת����float�ͣ��Ա��һ��

	srcMat.copyTo(dstMat);
	
	srcMat = srcMat / 255.0;//ͼ���һ��

	//gamma����
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

	imshow("ԭͼ", srcMat);
	imshow("ֱ��ͼ��ǿ��", dstMat);
	waitKey(0);

}