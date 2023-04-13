#include <stdio.h>
#include "MemoryManagerTest.h"
#include "../Include/MemoryManager.h"
#include "../DataStructures/Include/Utility.h"



void TestFirstFitCoalescing()
{
    LIST *mem = initMemory(400000);
    Malloc(mem, 8000);
    Malloc(mem,12000);
    Malloc(mem,6000);
    Malloc(mem,2000);
    Malloc(mem,5000);
    Malloc(mem, 7000);
    freeMemoryLocation(mem, 12000);
    freeMemoryLocation(mem, 5000);
    Malloc(mem, 3000);
    freeMemoryLocation(mem, 6000);

/*
 * The predicted output should be:
 * 8K Busy, 3K busy, 15K free, 2K busy, 5K free, 7K busy
 * Checks FIRSTFIT when adding 3k, it goes into the 12K free instead of teh 5K free
 * Checks COALESCING by ensuring that when 6K is freed, it combines with 9K free becoming 15K free as the third node.
 */

}

void TestBestFitCoalescing()
{
    initMemory(30000);
    Malloc(10000);
    Malloc(9000);
    Malloc(3000);
    Malloc(7000);
    Malloc(1000);
    freeNode((NODE*) 7000);
    freeNode((NODE*) 9000);
    Malloc(6000);
    freeNode((NODE *) 3000);
/*
 * The predicted output should be:
 * 10K busy, 9K free, 3K busy, 6K busy, 2K free
 * Checks BESTFIT when 6k gets added to the node, it will go into the 7k free spot instead of the 9k free spot
 * Checks COALESCING by ensuring that the last two free nodes (1K free and 1K free) combine to output 2K free
 */

}


void TestAll(){
    printf("__________________Running List Test____________________\n");
    TestFirstFitCoalescing();
    TestBestFitCoalescing();
    printf("__________________List Test Finished____________________\n");

}