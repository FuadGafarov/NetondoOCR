#pragma once  
#ifndef CV_H OCR_EXPORTS
#define CV_H __declspec(dllexport)
#else  
#define CV_H __declspec(dllimport)
#endif

#include "include\opencv2\core.hpp"


using namespace cv;

void readAllLettersFromScreen();
vector<Mat> detectLetters(Mat image);
void test();

