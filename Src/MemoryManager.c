#include "../Include/MemoryManager.h"
#include <stdlib.h>
#include <stdio.h>
#include "../DataStructures/Include/Utility.h"
#include "../DataStructures/Include/LinkedList.h"
/**
 * @file MemoryManager.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 2/23/2023
 */

#define MINREQ 0x20000 //Minimum size of memory allowed
#define BEST_FIT 0 //True (1) or False (0) to use the best fit algorithm

/**
 * The memory manager created.
 */
LIST *manager;

/**
 * Creates a node for the user when prompted.
 * @param size amount of memory.
 * @param free is the node free of data.
 * @return pointer to node.
 */
NODE *createNode(size_t size, bool Free) {
    NODE *data;
    data->isFree = Free;
    data->size = size;
    return data;
}

/**
 * Creates a new memory manager structure by initiliazing the busy list, free list, memory list, and queue. Sets
 * the count equal to 0.
 * @return MEMORY structure pointer.
 */
LIST *initMemory(size_t maxSize){
    size_t required = maxSize;
    while(manager == NULL){
        manager = InitList(compare_size_t);
        required >>= 1;
    }
    Add(manager, maxSize);
    return manager;
}


/**
 * Changes to node isFree bool to true, and then coalesces the previous and before nodes to
 * @param start node to begin the loop at.
 */
int freeMemoryLocation(LIST* mem, NODE *curr) {

    if(curr->isFree){
            printf("ERROR: Node is already free!");
            return EXIT_FAILURE;
    }else{
            if(curr->previous->isFree){
                size_t sum = curr->previous->size + curr->size;
                curr->previous->size = sum;
                curr = curr->previous;
                UnlinkNodeByValue(mem, curr->next->size);
            }
            if(curr->next->isFree){
                size_t sum = curr->next->size + curr->size;
                curr->next->size = sum;
                curr = curr->next;
                UnlinkNodeByValue(mem, curr->previous->size);
            }
            return EXIT_SUCCESS;
    }
}

/**
 * Frees the memory manager from the windows memory manager.
 */
void freeMemory(){ free(manager);}



/**
* Finds the first free block of memory in the linked list that is the same or larger amount of size we need.
* @param start node to begin the loop at.
* @param size of space we need.
* @return the node with enough space.
*/
int findFree(NODE *start, size_t size) {
    NODE *curr = start;
    int count = 0;
    while (!curr->isFree || curr->size < size && !curr->isFree) {

        if (curr->next == NULL)
        {
            return -1;
        }
        curr = curr->next;
        count++;
    }
    return count;

}



/**
* Splits a page of memory if the size is larger than what is needed.
* @param page to split.
* @param amount of memory needed.
* @return new page;
*/
NODE *splitPage(LIST *mem, int pageIndex, size_t amount) {
    NODE *page = WalkToNode(mem->head, pageIndex);
    if (page->size == amount) {
        page->isFree = false;
        return page;
    } else {
        page->size = page->size - amount;
        page->isFree = true;
        InsertNodeBeforeTarget(manager, pageIndex + 1, amount);
    }
}


int bestFit(LIST *mem, size_t amount) {
    NODE *currNODE;
    NODE *best;
    int currIndex;
    int tempBest;

    currIndex = tempBest = findFree(manager->head, amount);
    currNODE = best = WalkToNode(mem->head, tempBest);

    while (currIndex < mem->count) {
        currIndex = findFree(currNODE, amount);
        currNODE = WalkToNode(mem, currIndex);
        if (best->size - amount > currNODE->size - amount){
            best = currNODE;
            tempBest = currIndex;
        }

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
NODE *requestMemory(LIST *mem, size_t amount) {
    NODE *temp = manager->head;
    NODE *freePage;
    int freeIndex = findFree(temp, amount);
    if (BEST_FIT) {
        freeIndex = bestFit(mem, amount);
        freePage = splitPage(mem, freeIndex , amount);
    } else {
        freePage = splitPage(mem, freeIndex, amount);
        return freePage;
    }
}

/**
 * Allocates memory inside the memory manager created with the intialization function.
 * @param size of memory to allocate
 * @return pointer to the memory location of the allocation.
 */
NODE *Malloc(LIST *mem, size_t size) {
    return requestMemory(mem, size);
}

void DumpMemoryList(LIST *mem) {
    printf("___Memory Manager Dump___\n");
    NODE *curr = mem->head;
    while (curr != NULL) {
        if (curr->isFree) {
            printf("*** Size: %zu  || Free ***\n", curr->size);
        } else {
            printf("*** Size: %zu  || Busy ***\n", curr->size);
        }
        curr = curr->next;
    }
}


