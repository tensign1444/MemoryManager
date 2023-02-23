
# Data Structure Library

This is a small data structure library written in C. A data structure is a storage that is used to store and organize data. It is a way of arranging data on a computer so that it can be accessed and updated efficiently.[1](https://www.geeksforgeeks.org/data-structures/) The library includes a doubly linked-list, Queue, and Stack along with test cases for each.

## Linked List
A linked-list is a generic data structure that grows and shrinks dynamically. It usually is implemented with a series of individually allocated nodes that point from one item to the next, in a specified order. Nodes can be added and inserted arbitrarily in O(1) time if a link to the insertion/deletion point is known ahead of time. Searching a linked-list is an O(n) operation.

There are different types of linked-lists: doubly-linked, circular, and more. We implemented a doubly-linked list that tracks pointers for the head and tail of the list, which point to the first and last node, respectively.

## Stack
A stack is a Last In First Out (LIFO) data structure that uses the Push and Pop operations to add and remove data. It is often implemented on top of arrays and linked lists. We use our Linked List Library to implement our Stack. 

## Queue
The queue data structure is similar to, but opposite of, a stack. It operates in a First In First Out (FIFO) order and uses Enqueue and Dequeue operations to add and remove data. We use our Linked List Library to implement our Queue.

## What Data Type?
This library is done with a void pointer data type to make the structures generic. The reason we use a void pointer is because C does not have a generic data type. By using the void pointer, this pointer can point to any type of data.

## Documentation
A detailed [PDF](https://github.com/tensign1444/CDataStructures/blob/master/Documentation/DataStructuresDocumentation.pdf) with all the documentation for our library. The PDF was generated using DoxyGen with our header file comments.

## Installation
Below is one method of installation using Cmake.
1. Download [source code](https://github.com/tensign1444/CDataStructures/releases/tag/1.0.0)
2. Add into project directory.

## Usage

1. Inside `CMakeLists.txt` add
```
//This sets a variable named SOURCE_FILES to the location of our source files. If your file directory is different then just adjust to fit your machine.
set(SOURCE_FILES Src/LinkedList/LinkedList.c Util/Utility.c Src/Queue/Queue.c Src/Stack/Stack.c Test/TestRun.c Test/LinkedListTest.c Test/StackTest.c Test/StackTest.c)

add_library(DataStructures ${SOURCE_FILES}) //creates the library

add_executable({Your name of Executable} {Your source files}) //creates the executable

target_link_libraries({Your name of Executable} PRIVATE DataStructures) // this tells CMake to link the executable and library
```
2. Link the header file to your file. (Make sure the `include` folder is inside current directory.)
```angular2html
    #include "../../Include/LinkedList.h"
    #include "../Include/Stack.h"
    #include "../Include/Utility.h"
    #include "../Include/Queue.h"
```
3. Create LinkedList, Queue or Stack.
```angular2html
    STACK *ourStack = InitStack((compare) compare_int32_t);
    LIST *listHolder = InitList((compare) compare_int32_t);
    QUEUE *ourQueue = InitQueue((compare) compare_int32_t);
```
4. Use structures as intended.
    
## Authors

- [@tensign1444](https://github.com/tensign1444)
- [@michaelVaquilar](https://github.com/michaelVaquilar)
- [@Masa-dotcom](https://github.com/Masa-dotcom)



## Feedback

If you have any feedback, please create an [Issue](https://github.com/tensign1444/CDataStructures/issues).

