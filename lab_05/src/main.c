#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "point_list.h"

int32_t read_point_from_txt(FILE *fin, int32_t *x, int32_t *y) {
    return fscanf(fin , "%d %d" , x , y) != 2;
}

int32_t read_point_from_bin(FILE *fin, int32_t *x, int32_t *y) {
    unsigned char buffer[6];
    if (fread(buffer, 1, 6, fin) == 6) {
        *x = ((int32_t)buffer[0] << 0) + ((int32_t)buffer[1] << 8) + ((int32_t)buffer[2] << 16);
        *y = ((int32_t)buffer[3] << 0) + ((int32_t)buffer[4] << 8) + ((int32_t)buffer[5] << 16);
        if (*x & (1 << 23)) {
            *x = -((~(*x - 1)) & ((1 << 24) - 1)); 
        }
        if (*y & (1 << 23)) {
            *y = -((~(*y - 1)) & ((1 << 24) - 1)); 
        }
        return 0;
    } else {
        return -1;
    }
}

int32_t main(int32_t argc, char *argv[]) {
    if (argc < 4)
        return -1;

    intrusive_list list;
    intrusive_list* l = &list;
    init_list(l);


    if (!strcmp(argv[1], "loadtext")) {
        FILE *fin = fopen(argv[2], "r");
        int32_t x, y;
        while (!read_point_from_txt(fin, &x, &y)) {
            add_point(l, x, y);
        }
        fclose(fin);
    } else
    if (!strcmp(argv[1], "loadbin")) {
        FILE *fin = fopen(argv[2], "rb");
        int32_t x, y;
        while (!read_point_from_bin(fin, &x, &y)) {
            add_point(l, x, y);
        }
        fclose(fin);
    } else {
        printf("wrong parameter\n");
        return 0;
    }
    
    if (!strcmp(argv[3], "savetext")) {
        FILE *fout = fopen(argv[4], "w");
        apply(l, print_point_to_file_txt, fout);
        fclose(fout);
    } else 
    if (!strcmp(argv[3], "savebin")) {
        FILE *fout = fopen(argv[4], "wb");
        apply(l, print_point_to_file_bin, fout);
        fclose(fout);
    } else 
    if (!strcmp(argv[3], "print")) {
        apply(l, print_point, argv[4]);
        printf("\n");
    } else
    if (!strcmp(argv[3], "count")) {
        int32_t cnt = 0;
        apply(l, count_point, &cnt);
        printf("%d\n", cnt);
    } else {
        printf("wrong parameter\n");
    }
    remove_all_points(l);
    return 0;
}