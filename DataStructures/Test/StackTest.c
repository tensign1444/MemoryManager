/**
 * @file StackTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/Stack.h"
#include "../Include/Utility.h"
//------------------------------------Add To List TEST------------------------------------

void StackTestPushAndPop(){
    int i = 10;
    STACK *ourStack = InitStack((compare) compare_int32_t);
    Push(ourStack,&i);
    void *result = Pop(ourStack);
    TestStack(ourStack, &i, result, "Push and Pop Once Test", false);
    DestroyStack(ourStack);
}


void StackTestPushPopMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    STACK *ourStack = InitStack((compare) compare_int32_t);
    Push(ourStack,&a);
    Push(ourStack,&b);
    Push(ourStack,&c);
    Push(ourStack,&d);
    Push(ourStack,&e);
    Push(ourStack,&f);
    Push(ourStack,&g);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    void *result =Pop(ourStack);
    TestStack(ourStack, &d, result, "Push and Pop Multiple Values Test", false);
    DestroyStack(ourStack);
}

void StackTestPopEmpty(){
    STACK *ourStack = InitStack((compare) compare_int32_t);
    void *result =Pop(ourStack);
    TestStack(ourStack, NULL, result, "Stack Pop Empty Stack Test", true);
    DestroyStack(ourStack);
}

void StackTestPopAll(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    STACK *ourStack = InitStack((compare) compare_int32_t);
    Push(ourStack,&a);
    Push(ourStack,&b);
    Push(ourStack,&c);
    Push(ourStack,&d);
    Push(ourStack,&e);
    Push(ourStack,&f);
    Push(ourStack,&g);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    Pop(ourStack);
    void *result =Pop(ourStack);
    TestStack(ourStack, NULL, result, "Stack Pop All Values Test", true);
    DestroyStack(ourStack);
}

//_____________________________Main Test Entry Point_________________________________


void RunAllStackTest(){
    printf("__________________Running Stack Test____________________\n");
    StackTestPushAndPop();
    StackTestPushPopMultipleValue();
    StackTestPopEmpty();
    StackTestPopAll();
    printf("__________________Stack Test Finished____________________\n");
}
