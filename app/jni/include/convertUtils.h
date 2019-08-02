//
// Created by Ming on 2019/7/28.
//

#ifndef CONVERTDEMO_CONVERTUTILS_H
#define CONVERTDEMO_CONVERTUTILS_H

#include <vector>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include "log.h"

#define IMG_RGB888 0
#define IMG_RGBA8888 1
#define IMG_BGR888 2
#define IMG_BGRA8888 3
#define IMG_NV21 4
#define IMG_BINARY 5

#define IMG_ANGLE_0 0
#define IMG_ANGLE_90 1
#define IMG_ANGLE_180 2
#define IMG_ANGLE_270 3
#define IMG_MIRROR_NONE 0
#define IMG_MIRROR_HOR 1
#define IMG_MIRROR_VER 2

using namespace cv;
typedef unsigned char uchar;

#ifdef __cplusplus
extern "C" {
#endif

void ConvertBytes2RGB(const char mode, const char rotate, const char mirror, const int width, const int height, const int length, const uchar* const, uchar* const output);

#ifdef __cplusplus
}
#endif

#endif //CONVERTDEMO_CONVERTUTILS_H
