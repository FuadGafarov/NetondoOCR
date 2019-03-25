#include <iostream>
#include <vector>
#include "OCR.h"
#include "Tess.h"
#include "CV.h"
#include "include\opencv2\highgui.hpp"

using namespace cv;
using namespace std;

		JNIEXPORT jobjectArray JNICALL Java_OCR_OCR_run (JNIEnv *env, jobject obj, jbyteArray jpgArray) {
			jobjectArray wordsJava, containerJava;
			string tempWords;
			jbyte* bmp= env->GetByteArrayElements(jpgArray, 0); 
			Mat temp = imread("input/vs.jpg", 0);
			vector<Mat> letterBoxes = detectLetters(temp);

			containerJava = (jobjectArray)env->NewObjectArray(letterBoxes.size(),env->FindClass("java/lang/String"),env->NewStringUTF(""));
			
			for(int i = 0; i < letterBoxes.size(); i++) {
				//env->NewStringUTF(env, getWords(letterBoxes[i], 'e'));
				env->SetObjectArrayElement(containerJava, i, env->NewStringUTF(getWords(letterBoxes[i], 'e')));
			}
			//	(*env).NewStringUTF(env, tempWords);
			return containerJava;
		}