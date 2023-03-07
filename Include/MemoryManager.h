/**
 * @file MemoryManager.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 2/23/2023
 */

#ifndef MEMORYMANAGER_MEMORYMANAGER_H
#define MEMORYMANAGER_MEMORYMANAGER_H

#include "../DataStructures/Include/LinkedList.h"
#include "../DataStructures/Include/Queue.h"

/**
 * Memory structure, contains a freelist that holds our free memory, a busy list
 * holding the busy memory, and our memory list which combines the two in the order of actual memory.
 * Also contains a queue for objects waiting to be allocated into memory.
 */
typedef struct Memory{
    int Count;
    LIST *memory;
    QUEUE *queue;
}MEMORY;

typedef struct data{
    size_t size;
    bool isFree;
    void *data;
} DATA;


#endif //MEMORYMANAGER_MEMORYMANAGER_H
