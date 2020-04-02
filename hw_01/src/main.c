#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "stdlib.h"
#include "bmp.h"

int check_numbers(char *argv[]) {
	for (int32_t i = 4; i < 8; i++) {
		for (int j = 0; argv[i][j] != '\0'; j++) {
			if ('0' > argv[i][j] || argv[i][j] > '9') {
				return -1;
			}
		}
	}

	if (atoi(argv[4]) < 0) {return -1;}
	if (atoi(argv[5]) < 0) {return -1;}
	if (atoi(argv[6]) < 1) {return -1;}
	if (atoi(argv[7]) < 1) {return -1;}

	return 0;
}

int assign(BMPfile **pic, BMPfile *newPic) {
	deleteBMP(*pic);
	*pic = newPic;
	if (!*pic) 
		return -1;

	return 0;
}

int main(int argc, char *argv[]) {
    BMPfile *pic = NULL;

	if (argc != 8) {goto Error;}
	if (strcmp(argv[1], "crop-rotate")) 
		goto Error;
	
	if (check_numbers(argv)) 
		goto Error;
	
	int32_t x = atoi(argv[4]);
	int32_t y = atoi(argv[5]);
	int32_t w = atoi(argv[6]);
	int32_t h = atoi(argv[7]);

    if (assign(&pic, load_bmp(argv[2]))) 
    	goto Error;

    if (x + w > pic->width || y + h > pic->height)  
    	goto Error;

    x = x;
    y = pic->height - y - h;

    if (assign(&pic, crop(pic, x, y, w, h))) 
    	goto Error;

    if (assign(&pic, rotate(pic))) 
    	goto Error;

    if (save_bmp(pic, argv[3])) 
    	goto Error;

    deleteBMP(pic);
    return 0;

  Error:
    deleteBMP(pic); 
    return -1;
}