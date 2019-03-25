#include "include\opencv2\core.hpp"
#include "include\opencv2\highgui.hpp"
#include "include\opencv2\imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;



Mat CannyImg(Mat input) {
	  Mat output;
	  int thresh = 100;

	  Canny(input, output, thresh, thresh*2, 3);
	  return output;
}

vector<Mat> detectLetters(Mat image) {
	  vector<vector<Point> > contours;
	  vector<Vec4i> hierarchy;
	  vector<Rect> boundRect;
	  vector<Mat> ResultMat;

	  Mat temp, roi, element, Sobeled, Thresholded, Morphologed;
	  
	  //Cannied = CannyImg(image);
      Sobel(image, Sobeled, CV_8U, 1, 0, 3, 1, 0, cv::BORDER_DEFAULT);
      threshold(Sobeled, Thresholded, 0, 255, CV_THRESH_OTSU+CV_THRESH_BINARY);
	  element = getStructuringElement(cv::MORPH_RECT, cv::Size(10,10) );
	  morphologyEx(Thresholded, Morphologed, CV_MOP_CLOSE, element);
	  findContours(Morphologed, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0));
	 
	  vector<vector<Point> > contours_poly( contours.size() );
	      for( int i = 0; i < contours.size(); i++ )
        if (contours[i].size()>100)
        { 
            cv::approxPolyDP( cv::Mat(contours[i]), contours_poly[i], 3, true );
            cv::Rect appRect( boundingRect( cv::Mat(contours_poly[i]) ));
            if (appRect.width>appRect.height) 
                boundRect.push_back(appRect);
        }


		for(int i = 0; i < boundRect.size(); i++) {
			ResultMat.push_back(Mat( image, boundRect[i]));
		}



	  return ResultMat;
}

void test() {
}

Mat getROI2() {
	  vector<vector<Point> > contours;
	  vector<Vec4i> hierarchy;

	  Mat temp_ = imread("input/facebook2.jpg", 0);
	  Mat temp, roi;
	  temp = temp_(cv::Range(temp_.rows / 2, temp_.rows), cv::Range(0, temp_.cols));
	  findContours( CannyImg(temp), contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
	  			imshow("", CannyImg(temp));
			waitKey();
	for( size_t i = 0; i < contours.size(); i++ ){

		Rect r = boundingRect( contours[i] );
		if(r.height > 100 && r.width > 100) {
					Mat roi = Mat( temp, r );
			imshow("", roi);
			waitKey();
		}

    }

	return temp_;
}