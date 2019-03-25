#include<vector>
#include <chrono>
#include <iostream>
#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"
#include "include\opencv2\core.hpp"


using namespace std;
using namespace cv;

char* getWords(Mat image, char lang) {
	vector <string> a;
	string retData = "";
		typedef std::chrono::high_resolution_clock Clock;
		auto t1 = Clock::now();
		char *outText;
		tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
	
	
		 if (api->Init("./", "eng")) {
			fprintf(stderr, "Could not initialize tesseract.");
			exit(1);
		}
		api->SetPageSegMode(static_cast<tesseract::PageSegMode>(3));
		api->SetImage((uchar*)image.data, image.size().width, image.size().height, image.channels(), image.step1());
		api->Recognize(0);

		outText = api->GetUTF8Text();
		api->End();
		//pixDestroy(&image);

		auto t2 = Clock::now();
		std::chrono::duration<double, std::milli> fp_ms = t2 - t1;
		return outText;
}