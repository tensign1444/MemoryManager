/**
 * @file LinkedList.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include <stdbool.h>
#include <string.h>

/**
 * function that compares two elements.
 * @return 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
typedef int (*compare)(const void *,const void *);



/**
 * Node structure to hold the value along with the next and previous nodes.
 */
typedef struct Node{
    void **value;
    struct Node *next;
    struct Node *previous;
} NODE;

/**
 * List structure to hold our head, tail, count and compareTo function.
 */
typedef struct LList{
    NODE *head;
    NODE *tail;
    int count;
    compare CompareTo;
} LIST;


/**
 * Initializes our linked list so we have a memory location for it.
 * Using calloc so that the memory is already set to 0 instead of empty.
 * @param Compare compareable function for the list.
 * @return memory location of the list created, NULL if it failed to allocate memory.
 */
LIST* InitList(compare Compare);

/**
 * Adds a value to the linked list.
 * @param list to Add too.
 * @param value to be added.
 */
void Add(LIST *list, void *value);

/**
 * Gets the value at the specific index.
 * @param list to search.
 * @param index to get value at.
 * @return the value at the index.
 */
void *Get(LIST *list, int index);

/**
 * Destroys the list aka get's rid of the memory location by freeing the allocated memory.
 * @param list to destroy.
 */
void DestroyList(LIST *list);

/**
 * Prints list to console line by line
 * @param list to write to console
 */
void DumpList(LIST *list);

/**
 * Finds the index of a specific value.
 * @param list to search.
 * @param value to look for.
 * @return int, the index of the value.
 */
int IndexOf(LIST *list,void *value);

/**
 * Inserts a node (aka value) before a specific index.
 * @param list to insert Node in.
 * @param index to insert new value at.
 * @param newValue new value to be inserted.
 */
void InsertNodeBeforeTarget(LIST *list, int index, void *newValue);

/**
 * Inserts the new Node (aka value) after the specified index.
 * @param list to insert Node in.
 * @param index to insert new value at.
 * @param newValue the new value to insert.
 */
void InsertNodeAfterTarget(LIST *list, int index, void *newValue);

/**
 * Removes a node by the specified value.
 * @param list to unlink Node from.
 * @param value in the node we want to remove.
 * @return true if the node was removed, false otherwise.
 */
bool UnlinkNodeByValue(LIST *list, void *value);

/**
 * Removes a specific index.
 * @param list to remove value from.
 * @param index to remove
 * @return the data that was stored at the node that was removed.
 */
void *RemoveByIndex(LIST *list, int index);

/**
 * Walks to an index inside a specific node.
 * @param temp the node to walk.
 * @param location to walk to.
 * @return NODE, the node walked to.
 */
NODE *WalkToNode(NODE *temp,int location);

/**
 * Finds the middle of the list.
 * @param start Node
 * @return the middle node
 */
NODE *findMid(NODE *start);

/**
 * Sorts the two nodes given.
 * @param list that the values are from.
 * @param leftCursor the left data value
 * @param rightCursor the right data value
 * @return new sorted node.
 */
NODE *Sort(LIST *list, NODE *leftCursor, NODE *rightCursor);

/**
 * Uses merge sort to sort the linkedlist in ascending order.
 * @param list to sort.
 * @param start node
 * @return the new sorted node or list
 */
NODE *MergeSort(LIST *list, NODE *start);

/**
 * Calls MergeSort. Simple function for user to call
 * @param list to sort.
 */
void SortList(LIST *list);

#endif //DATASTRUCTURES_LINKEDLIST_H
