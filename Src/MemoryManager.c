#include "../Include/MemoryManager.h"
#include <stdlib.h>
#include "../DataStructures/Include/Utility.h"
/**
 * @file MemoryManager.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 2/23/2023
 */

/**
 * Creates a new memory manager structure by initiliazing the busy list, free list, memory list, and queue. Sets
 * the count equal to 0.
 * @return MEMORY structure pointer.
 */
MEMORY *CreateMemoryManager(){
        MEMORY *manager = (MEMORY*)calloc(1, sizeof(MEMORY));
        manager->busyList = InitList(compare_int64_t);
        manager->freeList = InitList(compare_int64_t);
        manager->memory = InitList(compare_int64_t);
        manager->queue = InitQueue(compare_int64_t);
        manager->Count = 0;
        return manager;
}
