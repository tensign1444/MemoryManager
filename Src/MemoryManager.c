#include "../Include/MemoryManager.h"
#include <stdlib.h>
#include <mman.h>
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

#define MIN_ALLOC_SIZE 4096


static LIST *manager;


#define MINREQ 0x20000

static MEMORY *initMemory(size_t maxSize){
    size_t required = maxSize;
    while(manager == NULL){
        manager = malloc(required);
        if (required < MINREQ)
        {
            if(manager)
            {
                free(manager);
            }
            printf("Cannot allocate enough memory\n");
            exit(ENOMEM);
        }
        required >>= 1;
    }
}

static void freeMemory(){ free(manager);}

DATA *createData(void *item, size_t size, bool free){
    DATA data;
    data.isFree = free;
    data.size = size;
    data.data = item;
}

static NODE *findFree(NODE **last, size_t size){
    NODE *curr = manager->head;
    while (curr && !(curr->value->isFree && curr->size >= size))
    {
        *last = curr;
        curr = curr->next;
    }
    return curr;
} // this finds the block that we originally partitioned from


static NODE *requestMemory(size_t amount){
    NODE *last = NULL;
    NODE *block = findFree(NULL, amount);
    if (block->value->size >= amount)
    {
        return block;
    }
    // Append new block to list
    block = manager + endpos;
    endpos += META_SIZE + size;
    if (last)
    {
        last->next = block;
    }
    else
    {
        first_block = block;
    }
    block->free = 0;
    block->next = NULL;
    block->size = size;
    return block;
}

MEMORY *Malloc(bool bestFit, MEMORY *mem, size_t item){

}
