// 6_4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <opencv.hpp>
using namespace cv;

int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\lena.jpg", 1);
	if (srcMat.empty()) return -1;

    cv::Point2f pts1[] = {
		cv::Point2f(150, 150),
		cv::Point2f(150, 300),
		cv::Point2f(350, 300),
		cv::Point2f(350,150) };
    cv::Point2f pts2[] = {
		cv::Point2f(200, 150),
		cv::Point2f(200, 300),
		cv::Point2f(340, 270),
		cv::Point2f(340,180) };

	cv::Mat perspective_matrix = cv::getPerspectiveTransform(pts1, pts2);
	cv::warpPerspective(srcMat, dstMat, perspective_matrix, srcMat.size());
	
	cv::imshow("src", srcMat);
	cv::imshow("dat", dstMat);
	cv::waitKey(0);
    return 0;
}

