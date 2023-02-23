/**
 * @file Queue.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_QUEUE_H
#define DATASTRUCTURES_QUEUE_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

/**
 * Stack structure that holds our Queue which is an implementation of our linkedlist.
 */
typedef struct Queue{
    int Count;
    LIST *list;
}QUEUE;

/**
 * Initializes our queue and allocates memory for the queue and list.
 * @param Compare a compare function for the generic data type.
 * @return pointer to the queue created, null if it couldn't be created.
 */
QUEUE* InitQueue(compare Compare);

/**
 * Add's an item to the end of the queue.
 * @param ourQueue the queue to enqueue onto.
 * @param item void * item to add.
 */
void Enqueue(QUEUE *ourQueue,void *item);

/**
 * Dequeues the item at the front of the list (removes the first item).
 * @param ourQueue the queue to dequeue an item from.
 * @return the item removed.
 */
void* Dequeue(QUEUE *ourQueue);

/**
 * Checks if the queue is empty.
 * @param ourQueue the queue to check if it is empty.
 * @return true if empty, false otherwise.
 */
bool QueueisEmpty(QUEUE *ourQueue);

/**
 * Destroys the queue, aka freeing the memory
 * @param ourQueue the queue to destroy.
 */
void DestroyQueue(QUEUE *ourQueue);

#endif //DATASTRUCTURES_QUEUE_H
