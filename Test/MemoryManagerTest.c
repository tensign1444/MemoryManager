#include <stdio.h>
#include "../Include/MemoryManagerTest.h"
#include "../Include/MemoryManager.h"
#include "../DataStructures/Include/LinkedList.h"
#include "../DataStructures/Include/Utility.h"


void TestFirstFitCoalescing()
{
    LIST *mem = initMemory(40000, false);
    NODE *One = Malloc(mem,8000);
    NODE *Two = Malloc(mem,12000);
    NODE *Three =Malloc(mem,6000);
    NODE *Four = Malloc(mem,2000);
    NODE *Five =Malloc(mem,5000);
    NODE *Six =Malloc(mem,7000);
    freeMemoryLocation(mem,Two);
    freeMemoryLocation(mem, Five);
    NODE *Seven = Malloc(mem, 3000);
    freeMemoryLocation(mem, Three);
    //DumpMemoryList(mem);
    LIST *expected = InitList(compare_size_t);
    AddAndSet(expected, 8000, false);
    AddAndSet(expected, 3000, false);
    AddAndSet(expected, 15000, true);
    AddAndSet(expected, 2000, false);
    AddAndSet(expected,5000, true);
    AddAndSet(expected, 7000, false);

    TestMemoryManager(expected,mem, "Memory Manager Test 1", false);

    freeMemory(mem);
    DestroyList(expected);
/*
 * The predicted output should be:
 * 8K Busy, 3K busy, 15K free, 2K busy, 5K free, 7K busy
 * Checks FIRSTFIT when adding 3k, it goes into the 12K free instead of teh 5K free
 * Checks COALESCING by ensuring that when 6K is freed, it combines with 9K free becoming 15K free as the third node.
 */

}


void TestFirstFit2()
{
    LIST *mem = initMemory(40000, false);
    NODE *One = Malloc(mem,10000);
    NODE *Two = Malloc(mem,2200);
    NODE *Three =Malloc(mem,3400);
    NODE *Four = Malloc(mem,6000);
    NODE *Five =Malloc(mem,5000);
    NODE *Six =Malloc(mem,7000);
    freeMemoryLocation(mem,Three);
    freeMemoryLocation(mem, Four);
    NODE *Seven = Malloc(mem, 3000);
    freeMemoryLocation(mem, Seven);
    //DumpMemoryList(mem);
    LIST *expected = InitList(compare_size_t);
    AddAndSet(expected, 10000, false);
    AddAndSet(expected, 2200, false);
    AddAndSet(expected, 9400, true);
    AddAndSet(expected, 5000, false);
    AddAndSet(expected,7000, false);
    AddAndSet(expected, 6400, true);

    TestMemoryManager(expected,mem, "Memory Manager Test 2", false);

    freeMemory(mem);
    DestroyList(expected);
/*
 * The predicted output should be:
 * 8K Busy, 3K busy, 15K free, 2K busy, 5K free, 7K busy
 * Checks FIRSTFIT when adding 3k, it goes into the 12K free instead of teh 5K free
 * Checks COALESCING by ensuring that when 6K is freed, it combines with 9K free becoming 15K free as the third node.
 */

}



void TestBestFitCoalescing()
{
    LIST *mem = initMemory(30000, true);
    NODE *One = Malloc(mem,10000);
    NODE *Two = Malloc(mem,9000);
    NODE *Three = Malloc(mem,3000);
    NODE *Four = Malloc(mem,7000);
    NODE *Five = Malloc(mem,1000);
    freeMemoryLocation(mem,Four);
    freeMemoryLocation(mem,Two);
    NODE *Six = Malloc(mem,6000);
    freeMemoryLocation(mem,Three);

    LIST *expected = InitList(compare_size_t);
    AddAndSet(expected, 10000, false);
    AddAndSet(expected, 12000, true);
    AddAndSet(expected, 6000, false);
    AddAndSet(expected,1000, true);
    AddAndSet(expected,1000, false);

    TestMemoryManager(expected,mem, "Memory Manager Test Best Fit 1", false);

    freeMemory(mem);
    DestroyList(expected);
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
    TestFirstFit2();
    TestBestFitCoalescing();
    printf("__________________Memory Manager Test Finished____________________\n");

}

int main() {
    TestAll();
    return 0;
}