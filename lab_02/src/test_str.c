#include <assert.h>
#include <string.h>
#include "test_str.h"
#include "str.h"

void test_strlen() {
    char testStr1[50] = "Hello Dmitriy Sviridkin!!";
    char testStr2[] = "";
    assert(my_strlen(testStr1) == strlen(testStr1));
    assert(my_strlen(testStr2) == strlen(testStr2));
}

void test_strcpy() {
    char testStr1[20] = "Hello!";
    char testStr2[20] = "world";
    char testStr3[20] = "";
    my_strcpy(testStr1, testStr2);
    assert(!strcmp(testStr1, testStr2));
    my_strcpy(testStr2, testStr3);
    assert(!strcmp(testStr2, testStr3));
}

void test_strcmp() {
    char testStr1[] = "dorogoy, gde ty byl?";
    char testStr2[] = "begal!";
    char testStr3[] = "dorogoy, gde ty byl?";
    int myRes, correctRes;
    myRes = my_strcmp(testStr1, testStr2);
    correctRes = strcmp(testStr1, testStr2);
    assert(myRes * correctRes > 0 || (!myRes && !correctRes));
    myRes = my_strcmp(testStr1, testStr3);
    correctRes = strcmp(testStr1, testStr3);
    assert(myRes * correctRes > 0 || (!myRes && !correctRes));
}

void test_strcat() {
    char testStr1[20] = "keklol";
    char testStr2[20] = "orbidol";
    char testStr3[20] = "keklolorbidol";
    my_strcat(testStr1, testStr2);
    assert(!strcmp(testStr1, testStr3));
}
