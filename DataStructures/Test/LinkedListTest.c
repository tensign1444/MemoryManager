/**
 * @file LinkedListTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/LinkedList.h"
#include <string.h>
#include <assert.h>
#include "../Include/Utility.h"
#include <stdlib.h>



//------------------------------------Add To List TEST------------------------------------

void TestAddOne(){
    int i = 10;
    void *p = &i;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    void *result = Get(listHolder,0);
    TestList(listHolder, p, result, "Add One Value", false);
    DestroyList(listHolder);
}


void TestMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&a, false);
    Add(listHolder,&b, false);
    Add(listHolder,&c, false);
    Add(listHolder,&d, false);
    Add(listHolder,&e, false);
    Add(listHolder,&f, false);
    Add(listHolder,&g, false);
    int *result = Get(listHolder,2);
    TestList(listHolder, &c, result, "Add Multiple Values",false);
    DestroyList(listHolder);
}


void TestWholeList(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;

    LIST *listHolder = InitList((compare) compareIntArrays);
    Add(listHolder,&a, false);
    Add(listHolder,&b, false);
    Add(listHolder,&c, false);
    Add(listHolder,&d, false);
    Add(listHolder,&e, false);
    Add(listHolder,&f, false);
    Add(listHolder,&g, false);

    void *result = Get(listHolder, 3);

    TestList(listHolder, &d, result, "Test Whole List As Array", false);
}

//------------------------------------INDEX OF TEST------------------------------------

void TestIndexOf(){
    int i = 211;
    int x = 212;
    int y = 34;
    int z = 23;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);
    Add(listHolder,&z, false);
    int three = 3;
    int *thr = &three;
    int result = IndexOfValue(listHolder,&y);
    TestList(listHolder, thr, &result, "IndexOf Included int", false);
    DestroyList(listHolder);
}

void TestIndexOfFail(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);
    //[10,23,-24,34]
    int result = IndexOfValue(listHolder,&z);
    int expected = -1;
    TestList(listHolder,&expected, &result, "IndexOf Fail int",false);
    DestroyList(listHolder);
}

void TestWithRandomInsert(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&a, false);
    Add(listHolder,&b, false);
    Add(listHolder,&c, false);
    Add(listHolder,&d, false);
    Add(listHolder,&e, false);
    Add(listHolder,&f, false);

    int result = IndexOfValue(listHolder,&d);

    InsertNodeBeforeTarget(listHolder,4,&g, false);

    result = IndexOfValue(listHolder,&d);
    int expected = 5;
    TestList(listHolder, &expected, &result, "Add Multiple Values", false);
    DestroyList(listHolder);
}

//------------------------------------INSERT BEFORE TEST------------------------------------

void InsertBeforeTest(){
    int i = randomInt();
    int x = randomInt();
    int y = randomInt();
    int z = randomInt();
    LIST *listHolder = InitList(compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);

    InsertNodeBeforeTarget(listHolder,1,&z, false);
    int *result = Get(listHolder,0);
    TestList(listHolder,&z, result, "Inserted Before Element Test", false);
    DestroyList(listHolder);
}

//------------------------------------INSERT AFTER TEST------------------------------------

void InsertAfterTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);
    InsertNodeAfterTarget(listHolder,1,&z, false);
    int *result = Get(listHolder,1);
    TestList(listHolder,&z, result, "Insert After Element Test", false);
    DestroyList(listHolder);
}

void InsertAfterTestTwo(){
    int i = 10;
    int x = 23;
    int y = -24;
    int z = 34;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);
    InsertNodeAfterTarget(listHolder,2,&z, false);
    int *result = Get(listHolder,2);
    TestList(listHolder,&z, result, "Insert After Element Test Two", false);
    DestroyList(listHolder);
}

//------------------------------------REMOVE TEST------------------------------------

void removeTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);

    UnlinkNodeByValue(listHolder,&x);
    int *result = Get(listHolder,1);
    TestList(listHolder, &y, result, "Remove Node Test", false);
    DestroyList(listHolder);
}

void removeAllTest(){
    int i = 10;
    int x = 23;
    int y = -24;
    LIST *listHolder = InitList((compare) compare_int32_t);
    Add(listHolder,&i, false);
    Add(listHolder,&x, false);
    Add(listHolder,&y, false);

    UnlinkNodeByValue(listHolder,&x);
    UnlinkNodeByValue(listHolder,&i);
    int *result = Get(listHolder,0);
    TestList(listHolder, &y, result, "Remove All Nodes Test", false);
    DestroyList(listHolder);
}


//------------------------------------SORT TEST------------------------------------

void TestSort(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    //int expected[7] = {10,12,45,192,202,231,282};
    LIST *listHolder = InitList(compare_int32_t);
    Add(listHolder,&a, false);
    Add(listHolder,&b, false);
    Add(listHolder,&c, false);
    Add(listHolder,&d, false);
    Add(listHolder,&e, false);
    Add(listHolder,&f, false);
    Add(listHolder,&g, false);

    SortList(listHolder);

    void *result = Get(listHolder, listHolder->count - 1);

    TestList(listHolder, &d, result, "Sort List Test", false);
    DestroyList(listHolder);
}


//_____________________________Main Test Entry Point_________________________________


void RunAllListTest(){
    printf("__________________Running List Test____________________\n");
    TestAddOne();
    TestMultipleValue();
    TestWholeList();
    TestIndexOf();
    TestIndexOfFail();
    TestWithRandomInsert();
    InsertBeforeTest();
    InsertAfterTest();
    InsertAfterTestTwo();
    removeTest();
    removeAllTest();
    TestSort();
    printf("__________________List Test Finished____________________\n");
}


