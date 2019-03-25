#include <jni.h>
#include "include\opencv2\highgui.hpp"

#ifndef _Included_OCR
#define _Included_OCR
#ifdef __cplusplus
extern "C" {
#endif

	JNIEXPORT jobjectArray JNICALL Java_OCR_OCR_run(JNIEnv *, jobject, jbyteArray jpgArray);

#ifdef __cplusplus
}
#endif
#endif
