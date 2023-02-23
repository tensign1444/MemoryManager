/**
 * @file QueueTest.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include <stdio.h>
#include "../Include/Queue.h"
#include "../Include/Utility.h"
//------------------------------------Add To List TEST------------------------------------

void QueueTestPushAndPop(){
    int i = 10;
    QUEUE *ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(ourQueue,&i);
    void *result = Dequeue(ourQueue);
    TestQueue(ourQueue, &i, result, "Add One Value", false);
    DestroyQueue(ourQueue);
}


void QueueTestMultipleValue(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    QUEUE *ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(ourQueue,&a);
    Enqueue(ourQueue,&b);
    Enqueue(ourQueue,&c);
    Enqueue(ourQueue,&d);
    Enqueue(ourQueue,&e);
    Enqueue(ourQueue,&f);
    Enqueue(ourQueue,&g);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    void *result =Dequeue(ourQueue);
    TestQueue(ourQueue, &d, result, "Add Multiple Values", false);
    DestroyQueue(ourQueue);
}

void QueueTestDequeueEmpty(){
    QUEUE *ourQueue = InitQueue((compare) compare_int32_t);
    void *result =Dequeue(ourQueue);
    TestQueue(ourQueue, NULL, result, "Dequeue Empty Queue", true);
    DestroyQueue(ourQueue);
}

void QueueTestDequeueAll(){
    int a = 10, b = 202, c = 192, d = 282, e = 231, f = 12, g = 45;
    QUEUE *ourQueue = InitQueue((compare) compare_int32_t);
    Enqueue(ourQueue,&a);
    Enqueue(ourQueue,&b);
    Enqueue(ourQueue,&c);
    Enqueue(ourQueue,&d);
    Enqueue(ourQueue,&e);
    Enqueue(ourQueue,&f);
    Enqueue(ourQueue,&g);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    Dequeue(ourQueue);
    void *result =Dequeue(ourQueue);
    TestQueue(ourQueue, NULL, result, "Dequeue All Values", true);
    DestroyQueue(ourQueue);
}

//_____________________________Main Test Entry Point_________________________________


void RunAllQueueTest(){
    printf("__________________Running Queue Test____________________\n");
    QueueTestPushAndPop();
    QueueTestMultipleValue();
    QueueTestDequeueEmpty();
    QueueTestDequeueAll();
    printf("__________________Queue Test Finished____________________\n");
}
