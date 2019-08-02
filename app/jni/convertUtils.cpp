//
// Created by Ming on 2019/7/28.
//

#include "convertUtils.h"

static int convert2RGB(const char mode, const int width, const int height, const int length, const uchar* const input, Mat& srcImg)
{
    Mat tempImg;
    switch (mode)
    {
        case IMG_RGB888:
            if (width * height * 3 != length)
                return -1;
            memcpy(srcImg.data, input, length * sizeof(uchar));
            break;
        case IMG_RGBA8888:
            if (width * height * 4 != length)
                return -1;
            tempImg = Mat(height, width, CV_8UC4);
            memcpy(tempImg.data, input, length * sizeof(uchar));
            cvtColor(tempImg, srcImg, COLOR_RGBA2RGB);
            break;
        case IMG_BGR888:
            if (width * height * 3 != length)
                return -1;
            tempImg = Mat(height, width, CV_8UC3);
            memcpy(tempImg.data, input, length * sizeof(uchar));
            cvtColor(tempImg, srcImg, COLOR_BGR2RGB);
            break;
        case IMG_BGRA8888:
            if (width * height * 4 != length)
                return -1;
            tempImg = Mat(height, width, CV_8UC4);
            memcpy(tempImg.data, input, length * sizeof(uchar));
            cvtColor(tempImg, srcImg, COLOR_BGRA2RGB);
            break;
        case IMG_NV21:
            if (width * height * 3 / 2 != length)
                return -1;
            tempImg = Mat(height + height / 2, width, CV_8UC1);
            memcpy(tempImg.data, input, length * sizeof(uchar));
            cvtColor(tempImg, srcImg, COLOR_YUV2RGB_NV21);
            break;
        case IMG_BINARY:
            std::vector<uchar> buff(input, input + length);
            if (!(buff[0] == 0xFF && buff[1] == 0xD8))
            {
                buff.insert(buff.begin(), 0xFF);
                buff.insert(buff.begin()+1, 0xD8);
            }
            tempImg = imdecode(buff, IMREAD_COLOR);
            cvtColor(tempImg, srcImg, COLOR_BGR2RGB);
            std::vector<uchar>().swap(buff);
            if (tempImg.rows != height || tempImg.cols != width)
            {
                tempImg.release();
                return -1;
            }
            break;

    }
    tempImg.release();
    return 0;
}

static void flipMat(const char rotate, const char mirror, Mat& srcImg, Mat& dstImg)
{
    Mat tempImg;
    switch (rotate)
    {
        case IMG_ANGLE_0:
            tempImg = srcImg;
            break;
        case IMG_ANGLE_90:
            transpose(srcImg, tempImg);
            flip(tempImg, tempImg, 1); //顺时针90°
            break;
        case IMG_ANGLE_180:
            flip(srcImg, tempImg, -1);
            break;
        case IMG_ANGLE_270:
            transpose(srcImg, tempImg);
            flip(tempImg, tempImg, 0); //顺时针270°
            break;
    }

    switch (mirror)
    {
        case IMG_MIRROR_NONE:
            dstImg = tempImg;
            break;
        case IMG_MIRROR_HOR:
            flip(tempImg, dstImg, 1);
            break;
        case IMG_MIRROR_VER:
            flip(tempImg, dstImg, 0);
            break;
    }

    tempImg.release();
}

/**
 * @param mode
 * @param rotate
 * @param mirror
 * @param width
 * @param height
 * @param inLen
 * @param input
 * @param outLen
 * @param output
 */
void ConvertBytes2RGB(const char mode, const char rotate, const char mirror, const int width, const int height, const int length, const uchar* const input, uchar* const output)
{
    Mat srcImg = Mat(height, width, CV_8UC3);
    if (convert2RGB(mode, width, height, length, input, srcImg))
    {
        srcImg.release();
        return;
    }

    Mat dstImg;
    flipMat(rotate, mirror, srcImg, dstImg);

    memcpy(output, dstImg.data, width * height * 3 * sizeof(uchar));

    srcImg.release();
    dstImg.release();
}
