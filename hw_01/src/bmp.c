#include "bmp.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const int32_t offsetToSize = 2;
const int32_t offsetToWidth = 18;
const int32_t offsetToHeight = 22;
const int32_t offsetToSizeImage = 34;
const int32_t offsetToPixels = 54;


void refresh_bytes(BMPfile *picture) {
	memcpy(picture->bytes + offsetToSize, &picture->size, 4);
	memcpy(picture->bytes + offsetToWidth, &picture->width, 4);
	memcpy(picture->bytes + offsetToHeight, &picture->height, 4);
	memcpy(picture->bytes + offsetToSizeImage, &picture->sizeImage, 4);
}

void refresh_variables(BMPfile *picture) {
	memcpy(&picture->size, picture->bytes + offsetToSize, 4);
	memcpy(&picture->width, picture->bytes + offsetToWidth, 4);
	memcpy(&picture->height, picture->bytes + offsetToHeight, 4);
	memcpy(&picture->sizeImage, picture->bytes + offsetToSizeImage,4);
	picture->widthInBytes = picture->width * 3 + picture->width % 4;
}

void deleteBMP(BMPfile *picture) {
	if (picture) 
		free(picture->bytes);
	free(picture);
}

BMPfile* create_alike(BMPfile *picture, int32_t newWidth, int32_t newHeight) { /*create with the same header*/
	BMPfile *newPicture = malloc(sizeof(BMPfile));
	if (!newPicture) goto Error;

	newPicture->height = newHeight;
	newPicture->width = newWidth;
	newPicture->widthInBytes = newWidth * 3 + newWidth % 4;
	newPicture->sizeImage = newPicture->height * newPicture->widthInBytes;
	newPicture->size = offsetToPixels + newPicture->sizeImage;

	newPicture->bytes = malloc(newPicture->size);
	if (!newPicture->bytes) goto Error;

	memcpy(newPicture->bytes, picture->bytes, offsetToPixels);
	refresh_bytes(newPicture);
	return newPicture;
   
  Error:
  	deleteBMP(newPicture);
   	return NULL;		
}


BMPfile* load_bmp(char *fileName) {
	BMPfile *newPicture = NULL;
	FILE *file = fopen(fileName, "rb");
	if (!file) goto Error; 

	fseek(file, 0L, SEEK_END);
	int32_t fsize = ftell(file);
	fseek(file, 0L, SEEK_SET);
	
	newPicture = malloc(sizeof(BMPfile));
	if (!newPicture) goto Error;
	newPicture->bytes = malloc(fsize);
	if (!newPicture->bytes) goto Error;

	fread(newPicture->bytes, 1, fsize, file);
	refresh_variables(newPicture);

	fclose(file);
	return newPicture;
  
  Error:
  	deleteBMP(newPicture);
  	if (file) fclose(file);
   	return NULL;
}

BMPfile* crop(BMPfile *picture, int32_t x, int32_t y, int32_t newWidth, int32_t newHeight) {
	BMPfile *newPicture = create_alike(picture, newWidth, newHeight);
	if (!newPicture) {return NULL;}

	char *itNewPic = newPicture->bytes + offsetToPixels;
	char *itPic = picture->bytes + offsetToPixels;

	itPic += y * picture->widthInBytes;
	for (int32_t i = 0; i < newHeight; i++) {
		memcpy(itNewPic, itPic + x * 3, newWidth * 3);
		memset(itNewPic + newWidth * 3, 0, newWidth % 4); //aligment
		itNewPic += newPicture->widthInBytes;
		itPic += picture->widthInBytes;
	}

	return newPicture;
}

BMPfile* rotate(BMPfile *picture) {
	BMPfile *newPicture = create_alike(picture, picture->height, picture->width);
	if (!newPicture) {return NULL;}

	char *itNewPic = newPicture->bytes + offsetToPixels;
	char *itPic = 0;

	for (int32_t i = picture->width - 1; i >= 0; i--) {
		itPic = picture->bytes + offsetToPixels + i * 3;
		for (int32_t j = 0; j < picture->height; j++) {
			memcpy(itNewPic, itPic, 3);
			itNewPic += 3;
			itPic += picture->widthInBytes; 
		}
		memset(itNewPic, 0, newPicture->width % 4); //aligment
		itNewPic += newPicture->width % 4;
	}

	return newPicture;	
}

int32_t save_bmp(BMPfile *picture, char *fileName) {
	FILE *file = fopen(fileName, "wb");
	if (!file) {return -1;} 

	refresh_bytes(picture);
	fwrite(picture->bytes, 1, picture->size, file);

	fclose(file);
	return 0;
}


