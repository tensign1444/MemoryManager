/**
 * @file LinkedList.c
 *
 * @author Tanner Ensign, Michael Vaquilar, Masaya Takahashi
 *
 * @date 1/31/2023
 */

#include "../../Include/LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

LIST* InitList(compare Compare){
    LIST *list = malloc(sizeof(LIST));
    if(list == NULL){
        return NULL;
    }
    list->CompareTo = Compare;
    list->count = 0;
    return list;
}

NODE *GetHead(NODE *temp) {
    NODE *curr = temp;
    while (curr->previous != NULL) {
        curr = curr->previous;
    }
    return curr;
}

NODE *GetTail(NODE *temp){
    NODE *curr = temp;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    return curr;
}


void Add(LIST *list, size_t value) {
    NODE *pList = malloc(sizeof(NODE));
    if(pList == NULL){
        return;
    }
    pList->size = value;
    pList->next = pList->previous = NULL;

    if(list->count <= 0) {
        list->head = list->tail = pList;
        list->head->isFree = list->tail->isFree = true;
    }
    else{
        NODE* curr = list->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = pList;
        curr->next->previous = curr;
        list->tail = curr->next;
    }
    list->count++;
}


size_t Get(LIST *list, int index){
    if(list->count <= 0)
        return EXIT_FAILURE;
    NODE *curr = WalkToNode(list->head, index);
    return curr->size;
}



void DestroyList(LIST *list){
    free(list);
}


void DumpList(LIST *list){
    if(list->count <= 0){ return; }
    NODE *curr  = list->head;
    while(curr != NULL){
        printf("%d\n", curr->size);
        if(curr->next == NULL){break;}
        curr = curr->next;
    }
}

int IndexOfValue(LIST *list,size_t value){
    if(list->count <= 0) { return -1;}
    NODE *curr  = list->head;
    int counter = 1;
    while(curr != NULL){
        if(list->CompareTo(&curr->size, &value) == 0){ return counter; }
        if(curr->next == NULL) { return EXIT_FAILURE; }
        curr = curr->next;
        counter++;
    }
    return -1;
}

void InsertNodeBeforeTarget(LIST *list, int index, size_t newValue){
    if(list->count <= 0){
        Add(list, newValue);
        return;
    }
    else if(index == 1){
        NODE* temp = malloc(sizeof(NODE));
        temp->size = newValue;
        temp->next = list->head;
        temp->isFree = false;
        temp->next->previous = temp;
        temp->previous = NULL;
        list->head = temp;
        list->tail = WalkToNode(temp, list->count);
    }
    else{
        NODE *curr  = WalkToNode(list->head, index - 1);
        NODE* temp = malloc(sizeof(NODE));
        temp->size = newValue;
        temp->isFree = false;
        temp->next = curr;
        temp->previous = curr->previous;
        temp->next->previous = temp;
        temp->previous->next = temp;

        list->head = GetHead(temp);
        list->tail = GetTail(temp);
    }
    list->count++;
}

void InsertNodeAfterTarget(LIST *list, int index, size_t newValue){
    if(list->count <= 0){
        return;
    }
    InsertNodeBeforeTarget(list,index + 1, newValue);
}

bool UnlinkNodeByValue(LIST *list, size_t value){
    if(list->count <= 0){ return false; }
    else if(list->count == 1){list->head = NULL; list->tail = NULL; list->count--; true;}
    else if(list->CompareTo((const void *) list->head->size, (const void *) value) == 0){
        list->head->next->previous = NULL;
        list->head = list->head->next;
        list->tail = GetTail(list->head);
        list->count--;
        return true;
    }
    else if(list->CompareTo((const void *) list->tail->size, (const void *) value) == 0){
        list->tail->previous->next = NULL;
        list->tail = list->tail->previous;
        list->head = GetHead(list->tail);
        list->count--;
        return true;
    }else{
            int indexOfTarget = IndexOfValue(list,value);

        NODE *curr  = WalkToNode(list->head, indexOfTarget - 1);

        curr->next->previous = curr->previous;
        curr->previous->next = curr->next;
        curr = curr->next;
        list->head = GetHead(curr);
        list->tail = GetTail(curr);
        list->count--;
        return true;
    }
}

size_t RemoveByIndex(LIST *list, int index){
    size_t value = Get(list, index);
    UnlinkNodeByValue(list, value);
    return value;
}

NODE *WalkToNode(NODE *temp,int location){
    NODE *curr  = temp;
    for(int i = 0; i < location; i++){
        curr = curr->next;
    }
    return curr;
}

NODE *findMid(NODE *start){
    NODE *fastTemp = start->next;
    NODE *slowTemp = start;

    while(fastTemp != NULL){
        fastTemp = fastTemp->next;

        if(fastTemp != NULL) {
            fastTemp = fastTemp->next;
            slowTemp = slowTemp->next;
        }
    }
    return slowTemp;
}

NODE *Sort(LIST *list, NODE *leftCursor, NODE *rightCursor){
    NODE *temp;

    if(leftCursor == NULL)
        return rightCursor;
    if(rightCursor == NULL)
        return leftCursor;
    int x;
    int *pAlloc = &x;
    *pAlloc = list->CompareTo((const void *) leftCursor->size, (const void *) rightCursor->size);
    if(*pAlloc < 0){
        temp = leftCursor;
        temp->next = Sort(list,leftCursor->next, rightCursor);
        list->tail = temp->next;
    }
    else{
        temp = rightCursor;
        temp->next = Sort(list,leftCursor, rightCursor->next);
        list->tail = temp->next;
    }
    return temp;
}

NODE *MergeSort(LIST *list, NODE *start){
    if(start == NULL || start->next == NULL)
        return start;

    NODE *endOf1st = findMid(start);
    NODE *begOf2nd = endOf1st->next;
    endOf1st->next = NULL;

    NODE *LHS = start;
    NODE *RHS = begOf2nd;

    LHS = MergeSort(list,LHS);
    RHS = MergeSort(list, RHS);

    NODE *sorted = Sort(list,LHS, RHS);

    list->head = sorted;

    return sorted;

}

void SortList(LIST *list){
    if(list->count <= 0){ return; }
    MergeSort(list,list->head);
}




