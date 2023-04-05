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
 * Creates a node for the user when prompted.
 * @param size amount of memory.
 * @param free is the node free of data.
 * @return pointer to node.
 */
NODE *createNode(size_t size, bool free);

/**
 * Initalize a new memory manager object.
 * @param maxSize the maximum size of memory for the memory manager to use.
 * @return pointer to the memory management list.
 */
LIST *initMemory(size_t maxSize);

/**
 * Changes to node isFree bool to true, and then coalesces the previous and before nodes to
 * @param start node to begin the loop at.
 */
int freeMemoryLocation(LIST* Mem, size_t start);

/**
 * Frees the memory manager from the windows memory manager.
 */
void freeMemory();


/**
* Finds the first free block of memory in the linked list that is the same or larger amount of size we need.
* @param start node to begin the loop at.
* @param size of space we need.
* @return the node with enough space.
*/
NODE *findFree(NODE *start, size_t size, bool found);


/**
* Splits a page of memory if the size is larger than what is needed.
* @param page to split.
* @param amount of memory needed.
* @return new page;
*/
NODE *splitPage(LIST *mem, NODE *page, size_t amount);


/**
 * Helper method that preforms a best fit memory management algorithm in our memory manager.
 * @param amount amount of bytes to allocate.
 * @return a pointer to the memory location allocated.
 */
NODE *bestFit(LIST *mem, size_t amount);

/**
* Request memory from the memory manager linked list created when initializing the linked list. This
* does not use Malloc. Instead Malloc is used in initializing the memory manager, so we only use it once and split
* that memory up.
* The user can use best fit or first fit. In order to use best fit, the BEST_FIT macro at the top of the source file must be
* set to 1.
* @param amount of memory needed.
* @return pointer to the new node with the size requested.
*/
NODE *requestMemory(LIST *mem, size_t amount);


/**
 * Allocates memory inside the memory manager created with the intialization function.
 * @param size of memory to allocate
 * @return pointer to the memory location of the allocation.
 */
NODE *Malloc(LIST *mem, size_t size);

/**
 * Dumps the memory to the console.
 */
void DumpMemoryList();





#endif //MEMORYMANAGER_MEMORYMANAGER_H
