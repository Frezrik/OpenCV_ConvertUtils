//
// Created by Ming on 2019/7/28.
//
#include <jni.h>
#include <string>
#include "log.h"

#include "convertUtils.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OPENCV_JNI_METHOD(METHOD_NAME) \
  Java_com_ming_utils_OpenCVUtils_##METHOD_NAME

/*JNIEXPORT jstring JNICALL
    OPENCV_JNI_METHOD(test)(JNIEnv* env, jobject thiz)
{
    std::string hello = "jni test";
    LOGD("jni test");
    return env->NewStringUTF(hello.c_str());
}*/

JNIEXPORT void JNICALL
    OPENCV_JNI_METHOD(convertBytesToRGB)(JNIEnv* env, jclass clazz, jbyte mode, jbyte rotate, jbyte mirror, jint width, jint height, jbyteArray input, jbyteArray output)
{
    jbyte *pInput = NULL, *pOutput = NULL;
    jint len = 0;

    if (input == NULL || output == NULL)
    {
        return;
    }

    jboolean inputCopy = JNI_FALSE;
    pInput = env->GetByteArrayElements(input, &inputCopy);
    len = env->GetArrayLength(input);

    jboolean outputCopy = JNI_FALSE;
    pOutput = env->GetByteArrayElements(output, &outputCopy);

    ConvertBytes2RGB(mode, rotate, mirror, width, height,
                     len, reinterpret_cast<uchar*>(pInput), reinterpret_cast<uchar*>(pOutput));

    if (input != NULL)
        env->ReleaseByteArrayElements(input, pInput, JNI_ABORT);
    if (output != NULL)
        env->ReleaseByteArrayElements(output, pOutput, 0);
}

#ifdef __cplusplus
}
#endif