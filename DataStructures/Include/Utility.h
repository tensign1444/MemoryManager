/**
 * @file Utility.h
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#ifndef DATASTRUCTURES_UTILITY_H
#define DATASTRUCTURES_UTILITY_H

#include "../Include/LinkedList.h"
#include "../Include/Queue.h"
#include "../Include/Stack.h"

/**
 * Compares two 32 bit integers to each-other.
 * @param element1 void pointer to the first integer.
 * @param element2 void pointer to the second integer.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_int32_t(const void *element1, const void *element2);

/**
 * Compares two 64 bit integers to each-other.
 * @param element1 void pointer to the first integer.
 * @param element2 void pointer to the second integer.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_int64_t(const void *element1, const void *element2);

/**
 * Compares two floats to each-other.
 * @param element1 void pointer to the first float.
 * @param element2 void pointer to the second float.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_float(const void *element1, const void *element2);

/**
 * Compares two double's to each-other.
 * @param element1 void pointer to the first double.
 * @param element2 void pointer to the second double.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_double(const void *element1, const void *element2);

/**
 * Compares two long doubles to each-other.
 * @param element1 void pointer to the first long double.
 * @param element2 void pointer to the second long double.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_long_double(const void *element1, const void *element2);

/**
 * Compares two char's to each-other.
 * @param element1 void pointer to the first char.
 * @param element2 void pointer to the second char.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_char(const void *element1, const void *element2);

/**
 * Compares two strings to each-other.
 * @param element1 void pointer to the first string.
 * @param element2 void pointer to the second string.
 * @return int, 1 when the first element is greater than the second, -1 when the first element is less than the second, 0 when both elements are equal.
 */
int compare_string(const void *element1, const void *element2);

/**
 * Compares to int arrays to see if they are similar.
 * @param a first int array.
 * @param b second int array.
 * @return 0 if not, 1 if equal.
 */
int compareIntArrays(int a[], int b[]);

/**
 * Small method for a list unit test, checks if two objects are equal, if so they passed.
 * @param listHolder linkedlist to test
 * @param expected output
 * @param actual output
 * @param testName name of the test
 * @param isNULL check if actual and expected both should be NULL
 */
void TestList(LIST *listHolder, void *expected, void *actual, const char* testName, bool isNULL);

/**
 * Small method for a list Queue test, checks if two objects are equal, if so they passed.
 * @param queue to test
 * @param expected output
 * @param actual output
 * @param testName name of the test
 * @param isNULL check if actual and expected both should be NULL
 */
void TestQueue(QUEUE *queue, void *expected, void *actual, const char* testName, bool isNULL);

/**
 * Small method for a Stack unit test, checks if two objects are equal, if so they passed.
 * @param stack to test
 * @param expected output
 * @param actual output
 * @param testName name of the test
 * @param isNULL check if actual and expected both should be NULL
 */
void TestStack(STACK *stack, void *expected, void *actual, const char* testName, bool isNULL);

/**
 * Generates a random 32 bit int.
 * @return randomly generated int.
 */
int randomInt();

/**
 * Converts a int LinkedList into an int array
 * @param listHolder the list to convert into an array
 * @return int array
 */
int * ToArray(LIST *listHolder);

#endif //DATASTRUCTURES_UTILITY_H
