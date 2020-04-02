#include <stddef.h>
#include <malloc.h>
#include "mergesort.h"

void copy_bytes(char *srcBegin, char *srcEnd, char *dest) {
	char *srcCurByte = srcBegin;
	char *destCurByte = dest;
	while (srcCurByte != srcEnd) {
		*destCurByte = *srcCurByte;
		destCurByte++;
		srcCurByte++;
	}
}

int merge(void *arrayVoid, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
	char *array = arrayVoid;
	char *buf = (char*)malloc(elements * element_size);
	if (!buf) return -1;
	size_t sizeLeft = elements / 2;
	char *arrLeftEnd = array + sizeLeft * element_size;
	char *arrRightEnd = array + elements * element_size;
	char *curLeftIt = array;
	char *curRightIt = array + sizeLeft * element_size;
	char *curBufIt = buf;

	while (curLeftIt != arrLeftEnd && curRightIt != arrRightEnd) {
		if (comparator(curLeftIt, curRightIt) <= 0) {
			copy_bytes(curLeftIt, curLeftIt + element_size, curBufIt);
			curLeftIt += element_size;
		} else {
			copy_bytes(curRightIt, curRightIt + element_size, curBufIt);
			curRightIt += element_size;
		}
		curBufIt += element_size;
	}
	while (curLeftIt != arrLeftEnd) {
		copy_bytes(curLeftIt, curLeftIt + element_size, curBufIt);
		curLeftIt += element_size;
		curBufIt += element_size;
	}
	while (curRightIt != arrRightEnd) {
		copy_bytes(curRightIt, curRightIt + element_size, curBufIt);
		curRightIt += element_size;
		curBufIt += element_size;
	}
	copy_bytes(buf, curBufIt, array);
	free(buf);
	return 0;
}

int mergesort(void *arrayVoid, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
	char *array = arrayVoid;
	size_t sizeLeft = elements / 2;
	size_t sizeRight = (elements + 1) / 2;
	char *arrLeft = array;
	char *arrRight = array + sizeLeft * element_size;

	if (elements == 1)
		return 0;
	if (mergesort(arrLeft, sizeLeft, element_size, comparator)) 
		return -1;
	if (mergesort(arrRight, sizeRight, element_size, comparator)) 
		return -1;
	if (merge(array, elements, element_size, comparator))
		return -1;
	return 0;
}