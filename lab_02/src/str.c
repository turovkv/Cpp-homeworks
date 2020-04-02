#include <stddef.h>
#include "str.h"

size_t my_strlen(const char *userstring) {
    const char *temp = userstring;
    while (*temp++);
    return temp - userstring - 1;
}

char *my_strcpy(char * restrict destination, const char * restrict source) {
    char *temp = destination;
    while (*source){
        *temp = *source;
        temp++; source++;
    }
    *temp = '\0';
    return destination;
}

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2){
        str1++; str2++;
    }
    return *str1 - *str2;
}

char *my_strcat(char * restrict str1, const char * restrict str2) {
    char *temp = str1;
    while (*temp) {
        temp++;
    }
    while (*str2){
        *temp = *str2;
        temp++; str2++;
    }
    *temp = '\0';
    return str1;
}


