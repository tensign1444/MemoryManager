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

#define MINREQ 0x20000 //Minimum size of memory allowed
#define BEST_FIT 0 //True or False to use the best fit algorithm

/**
 * The memory manager created.
 */
static LIST *manager;

/**
 * Creates a new memory manager structure by initiliazing the busy list, free list, memory list, and queue. Sets
 * the count equal to 0.
 * @return MEMORY structure pointer.
 */
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

/**
 * Frees the memory manager from the windows memory manager.
 */
static void freeMemory(){ free(manager);}

/**
 * Finds the first free block of memory in the linked list that is the same or larger amount of size we need.
 * @param start node to begin the loop at.
 * @param size of space we need.
 * @return the node with enough space.
 */
static NODE *findFree(NODE *start, size_t size, bool found){

    NODE *curr = start;
    while (curr->next != NULL) {
        if(curr->isFree)
            if(curr->size >= size)
                return curr;
        curr = curr->next;
    }
    if(found)
        return NULL;
    else{
        perror("No free memory!");
        exit(0);
    }
}


/**
 * Splits a page of memory if the size is larger than what is needed.
 * @param page to split.
 * @param amount of memory needed.
 * @return new page;
 */
static NODE *splitPage(NODE *page, size_t amount){
    if(page->size == amount){
        page->isFree = false;
        return page;
    }
    else{
        NODE *newPage = createNode(page->size - amount, true);
        page->size = amount;
        page->isFree = false;
        InsertNodeAfterTarget(manager, IndexOf(manager, page), newPage);
    }
}


static NODE *bestFit(size_t amount){
    NODE *curr;
    NODE *tempBest = findFree(manager->head, amount, false);
    while(true){
        curr = findFree(curr, amount, true);
        if(tempBest->size - amount > curr->size - amount)
            tempBest = curr;
    }
    return tempBest;
}


/**
 * Request memory from the memory manager linked list created when intializing the linked list. This
 * does not use Malloc. Instead Malloc is used in intializing the memory manager, so we only use it once and split
 * that memory up.
 * The user can use best fit or first fit. In order to use best fit, the BEST_FIT macro at the top of the source file must be
 * set to 1.
 * @param amount of memory needed.
 * @return pointer to the new node with the size requested.
 */
static NODE *requestMemory(size_t amount){
    NODE *temp = manager->head;
    NODE *freePage = findFree(temp, amount, false);
    if(BEST_FIT) {
        freePage = bestFit(amount);
        freePage = splitPage(freePage, amount);
    }else{
        freePage = splitPage(freePage, amount);
        return freePage;
    }
}

/**
 * Allocates memory inside the memory manager created with the intialization function.
 * @param size of memory to allocate
 * @return pointer to the memory location of the allocation.
 */
NODE *Malloc(size_t size){
    return requestMemory(size);
}
