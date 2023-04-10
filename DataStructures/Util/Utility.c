/**
 * @file Utility.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */
#include <inttypes.h>
#include <string.h>
#include "../Include/Utility.h"
#include "../Include/LinkedList.h"
#include <time.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

int compare_size_t(const void* a, const void* b) {
    const size_t* pa = (const size_t*) a;
    const size_t* pb = (const size_t*) b;
    if (*pa < *pb) {
        return -1;
    } else if (*pa > *pb) {
        return 1;
    } else {
        return 0;
    }
}


int compare_int32_t(const void *element1, const void *element2)
{
    const int32_t *e1 = (const int32_t*)element1;
    const int32_t *e2 = (const int32_t*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_int64_t(const void *element1, const void *element2)
{
    const int64_t *e1 = (const int64_t*)element1;
    const int64_t *e2 = (const int64_t*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_float(const void *element1, const void *element2)
{
    const float *e1 = (const float*)element1;
    const float *e2 = (const float*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_double(const void *element1, const void *element2)
{
    const double *e1 = (const double*)element1;
    const double *e2 = (const double*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_long_double(const void *element1, const void *element2)
{
    const long double *e1 = (const long double*)element1;
    const long double *e2 = (const long double*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_char(const void *element1, const void *element2)
{
    const char *e1 = (const char*)element1;
    const char *e2 = (const char*)element2;

    if (*e1 > *e2)
        return 1;
    else if (*e1 < *e2)
        return -1;

    return 0;
}

int compare_string(const void *element1, const void *element2)
{
    const char *e1 = (const char*)element1;
    const char *e2 = (const char*)element2;

    return strcmp(e1, e2);
}

int compareIntArrays(int a[], int b[]) {
   return memcmp(a, b, sizeof(a));
}

void TestList(LIST *listHolder, void *expected, void *actual, const char* testName, bool isNULL){
    if(isNULL && expected == NULL && actual == NULL){ printf("%s : PASSED\n", testName); }
    else if(listHolder->CompareTo(expected, actual) == 0){
        printf("%s : PASSED\n", testName);
    }else {
        printf("%s : FAILED expected: %d actual: %d\n", testName, expected, actual);
    }
}

int randomInt(){
    srand(time(NULL));
    int r = rand();
    return r;
}


