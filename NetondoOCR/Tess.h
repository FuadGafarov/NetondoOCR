#ifndef TESS_H
#define TESS_H

#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "include\opencv2\core.hpp"
#include<vector>

using namespace std;
using namespace cv;

char* getWords(Mat image, char lang);

#endif