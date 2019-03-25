#include <iostream>
#include "Tess.h"
#include "CV.h"
#include "include\opencv2\highgui.hpp"
#include "OCR.h"
#include "test_Test.h"

#define DLL_EXPORT

using namespace std;
using namespace cv;



		JNIEXPORT jint JNICALL Java_Sample1_main (JNIEnv *env, jobject obj) {
			Mat temp = imread("input/facebook1.jpg", 0);
			vector<Mat> letterBoxes = detectLetters(temp);

			for(int i = 0; i < letterBoxes.size(); i++) {
				getWords(letterBoxes[i], 'e');
			}

			return 0;
}