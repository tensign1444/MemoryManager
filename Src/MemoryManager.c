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
size_t endPosition = 0;


#define MINREQ 0x20000

static LIST *initMemory(size_t maxSize){
    size_t required = maxSize;
    while(manager == NULL){
        manager = InitList(compare_int64_t);
        if (required < MINREQ) // only enters if 128KB isn't available
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
    return manager;
}

static void freeMemory(){ free(manager);}

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
    NODE *temp = NULL;
    NODE *freePage = findFree(temp, amount);

    if(freePage) {
        freePage->value.isFree = true;
        return freePage;
    }
}

static NODE *splitPage(NODE *page, size_t amount){
    if(page->value.size == amount)
        return page;
    else{
        createNode()
    }
}



MEMORY *Malloc(bool bestFit, MEMORY *mem, size_t item){

}
