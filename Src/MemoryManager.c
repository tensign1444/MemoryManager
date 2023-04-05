#include "../Include/MemoryManager.h"
#include <stdlib.h>
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
#define BEST_FIT 0 //True or False to use the best fit algorithm

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
    data->value = &size;
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
        if (required < MINREQ) // only enters if 128KB isn't available
        {
            if(manager)
            {
                free(manager);
            }
            printf("Cannot allocate enough memory\n");
            exit(ENOMEM);
        }
        Add(manager, &maxSize, true);
        required >>= 1;
    }
    return manager;
}


/**
 * Changes to node isFree bool to true, and then coalesces the previous and before nodes to
 * @param start node to begin the loop at.
 */
int freeMemoryLocation(LIST* Mem, size_t start) {
    int indexOfNode = IndexOfValue(Mem, &start);
    NODE *curr = Mem->head;
    for(int i = 0; i < indexOfNode; i++){ curr = curr->next;}

    if(curr->value == &start){
        if(curr->isFree){
            printf("ERROR: Node is already free!");
            return EXIT_FAILURE;
        }else{
            if(curr->previous->isFree){
                size_t sum = (size_t) curr->previous->value + (size_t) curr->value;
                curr->previous->value = &sum;
                curr = curr->previous;
                UnlinkNodeByValue(Mem, curr->next->value);
            }
            if(curr->next->isFree){
                size_t sum = (size_t) curr->next->value + (size_t) curr->value;
                curr->next->value = &sum;
                curr = curr->next;
                UnlinkNodeByValue(Mem, curr->previous->value);
            }
            return EXIT_SUCCESS;
        }
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
NODE *findFree(NODE *start, size_t size, bool found) {

    NODE *curr = start;
    while (curr->next != NULL) {
        if (curr->isFree)
            if (curr->value >= size)
                return curr;
        curr = curr->next;
    }
    if (found)
        return NULL;
    else {
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
NODE *splitPage(LIST *mem, NODE *page, size_t amount) {
    if (page->value == amount) {
        page->isFree = false;
        return page;
    } else {
        NODE *newPage = createNode((size_t)page->value - amount, true);
        size_t newSize = (size_t) page->value - amount;
        page->value = &amount;
        page->isFree = false;
        InsertNodeAfterTarget(mem, IndexOfValue(manager, page->value), &newSize, false);
    }
}


NODE *bestFit(LIST *mem, size_t amount) {
    NODE *curr;
    NODE *tempBest = findFree(manager->head, amount, false);
    while (true) {
        curr = findFree(curr, amount, true);
        if (tempBest->value - amount > curr->value - amount)
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
NODE *requestMemory(LIST *mem, size_t amount) {
    NODE *temp = mem->head;
    NODE *freePage = findFree(temp, amount, false);
    if (BEST_FIT) {
        freePage = bestFit(mem, amount);
        freePage = splitPage(mem, freePage, amount);
    } else {
        freePage = splitPage(mem,   freePage, amount);
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

void DumpMemoryList() {
    LIST *freeList;
    LIST *busyList;
    NODE *curr = manager->head;
    while (curr->next != NULL) {
        if (curr->isFree) {
            Add(freeList, curr, true);
        } else {
            Add(busyList, curr, false);
        }
        curr = curr->next;
    }

    curr = freeList->head;
    printf("Free Memory:\n");
    while (curr->next != NULL) {
        printf("Size: %s", curr->value);
        curr = curr->next;
    }
    printf("Size: %s\n", curr->value);

    curr = busyList->head;
    printf("Busy Memory:\n");
    while (curr->next != NULL) {
        printf("Size: %s\n", curr->value);
    }
    printf("Size: %s", curr->value);
}


