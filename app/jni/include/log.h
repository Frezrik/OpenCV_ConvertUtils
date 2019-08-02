//
// Created by Ming on 2019/7/28.
//

#ifndef CONVERTDEMO_LOG_H
#define CONVERTDEMO_LOG_H

#include <android/log.h>
#define TAG "native_convert"
#define DEBUG 1

#define LOGD(...) if(DEBUG) __android_log_print(ANDROID_LOG_DEBUG,TAG,__VA_ARGS__) //Log.d
#define LOGI(...) if(DEBUG) __android_log_print(ANDROID_LOG_INFO,LOG_TAG, __VA_ARGS__) //Log.i
#define LOGW(...) if(DEBUG) __android_log_print(ANDROID_LOG_WARN,LOG_TAG, __VA_ARGS__) //log.w
#define LOGE(...) if(DEBUG) __android_log_print(ANDROID_LOG_ERROR,TAG,__VA_ARGS__) //Log.e
#define LOGF(...) if(DEBUG) __android_log_print(ANDROID_LOG_FATAL,LOG_TAG, __VA_ARGS__) //log.f


#endif //CONVERTDEMO_LOG_H
