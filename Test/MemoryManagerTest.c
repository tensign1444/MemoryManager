#include <stdio.h>
#include "../Include/MemoryManagerTest.h"
#include "../Include/MemoryManager.h"



void TestFirstFitCoalescing()
{
    LIST *mem = initMemory(40000);
    NODE *One = Malloc(mem,8000);
    NODE *Two = Malloc(mem,12000);
    NODE *Three =Malloc(mem,6000);
    NODE *Four = Malloc(mem,2000);
    NODE *Five =Malloc(mem,5000);
    NODE *Six =Malloc(mem,7000);
    freeMemoryLocation(mem,Two);
    freeMemoryLocation(mem, Five);
    Malloc(mem, 3000);
    freeMemoryLocation(mem, Three);
    DumpMemoryList(mem);

/*
 * The predicted output should be:
 * 8K Busy, 3K busy, 15K free, 2K busy, 5K free, 7K busy
 * Checks FIRSTFIT when adding 3k, it goes into the 12K free instead of teh 5K free
 * Checks COALESCING by ensuring that when 6K is freed, it combines with 9K free becoming 15K free as the third node.
 */

}

void TestBestFitCoalescing()
{
    LIST *mem = initMemory(30000);
    Malloc(mem,10000);
    Malloc(mem,9000);
    Malloc(mem,3000);
    Malloc(mem,7000);
    Malloc(mem,1000);
    freeMemoryLocation(mem,7000);
    freeMemoryLocation(mem,9000);
    Malloc(mem,6000);
    freeMemoryLocation(mem,3000);


/*
 * The predicted output should be:
 * 10K busy, 9K free, 3K busy, 6K busy, 2K free
 * Checks BESTFIT when 6k gets added to the node, it will go into the 7k free spot instead of the 9k free spot
 * Checks COALESCING by ensuring that the last two free nodes (1K free and 1K free) combine to output 2K free
 */

}


void TestAll(){
    printf("__________________Running Memory Manager Test____________________\n");
    TestFirstFitCoalescing();
    //TestBestFitCoalescing();
    printf("__________________Memory Manager Test Finished____________________\n");

}

int main() {
    TestAll();
    return 0;
}