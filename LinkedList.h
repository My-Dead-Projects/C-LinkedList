#pragma once
#include <stdlib.h>

typedef struct s_LinkedList_Node
{
    void * data;
    struct s_LinkedList_Node * next;
    struct s_LinkedList_Node * prev;

} LinkedList_Node;

typedef struct s_LinkedList
{
    size_t p_elementSize;
    size_t p_nodeCount;
    LinkedList_Node * head;
    LinkedList_Node * tail;

} LinkedList;

LinkedList_Node * LinkedList_Node_p_new(void * data, size_t size);
void LinkedList_Node_p_delete(LinkedList_Node * node);

LinkedList LinkedList_new(size_t elementSize);
void LinkedList_delete(LinkedList * list);
void LinkedList_pushBack(LinkedList * list, void * data);
