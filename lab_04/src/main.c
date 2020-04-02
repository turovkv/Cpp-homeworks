#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mergesort.h"

int int_comparator(const void *a, const void *b) {
    return atoi((char*)a) - atoi((char*)b);
}

int char_comparator(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int str_comparator(const void *a, const void *b) {
    return strcmp((char*)a, (char*)b);
}

size_t get_element_size(int argc, char *argv[]) {
    size_t element_size = 0;
    for (int i = 2; i < argc; i++) {
        if (element_size < strlen(argv[i]) + 1)
            element_size = strlen(argv[i]) + 1;
    }
    return element_size;
}

int main(int argc, char *argv[]) {
    int (*comparator)(const void*, const void *);
    if (!strcmp(argv[1], "int")) {
        comparator = int_comparator;
    } else
    if (!strcmp(argv[1], "char")) {
        comparator = char_comparator;
    } else
    if (!strcmp(argv[1], "str")) {
        comparator = str_comparator;
    } else {
        printf("WTF!??\n");
        return 0;
    }

    size_t elements = argc - 2;
    size_t element_size = get_element_size(argc, argv);
    if (!elements) 
        return 0;

    char arr[elements][element_size];
    
    for (size_t i = 0; i < elements; i++) {
        strcpy(arr[i], argv[i+2]);
    }

    if (!mergesort(*arr, elements, element_size, comparator)) {
        for (size_t i = 0; i < elements; i++) {
            printf("%s ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Error: memory allocation failed\n");
    }
    return 0;
} 
