#pragma once

#include "stdint.h"

typedef struct BMPfile {
    int32_t size;
    int32_t width;
    int32_t widthInBytes;
    int32_t height;
    int32_t sizeImage;
    char *bytes;
} BMPfile;

void deleteBMP(BMPfile *picture);

BMPfile* load_bmp(char *fileName);

BMPfile* crop(BMPfile *picture, int32_t x, int32_t y, int32_t newWidth, int32_t newHeight) ;

BMPfile* rotate(BMPfile *picture);

int32_t save_bmp(BMPfile *picture, char *fileName);
