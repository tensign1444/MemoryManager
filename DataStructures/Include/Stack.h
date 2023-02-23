/**
 * @file Stack.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include "../include/LinkedList.h"

/**
 * Stack structure that holds ourstack which is an implementation of our linkedlist.
 */
typedef struct Stack{
    int Count;
    LIST *list;
}STACK;

/**
 * Updates the count of the Stack.
 */
void UpdateCount();

/**
 * Initializes our stack and allocates memory for the queue and list.
 * @param Compare a compare function for the generic data type.
 * @return pointer to the stack made, NULL if it couldn't be made.
 */
STACK* InitStack(compare Compare);

/**
 * Checks if the stack is empty.
 * @param ourStack the stack to check if empty.
 * @return true if empty, false otherwise.
 */
bool StackisEmpty(STACK *ourStack);

/**
 * Pop's an item off the top of the stack.
 * @param ourStack the stack to pop an item off of.
 * @return the generic pointer to the item popped off.
 */
void *Pop(STACK *ourStack);

/**
 * Gives the user the item at the top off the stack
 * without removing the item.
 * @param ourStack the stack to peek into
 * @return the value at the top of the stack.
 */
void *Peek(STACK *ourStack);

/**
 * Pushes a generic pointer to an item onto the top of the stack.
 * @param ourStack the stack to push onto.
 * @param data void pointer to the data to pop onto the stack.
 */
void Push(STACK *ourStack, void *data);

/**
 * Destroys the stack, aka freeing the memory.
 * @param ourStack the stack to destroy.
 */
void DestroyStack(STACK *ourStack);

#endif //DATASTRUCTURES_STACK_H
