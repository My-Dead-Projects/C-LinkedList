#include "LinkedList.h"
#include <string.h>
#include <stdio.h>

LinkedList_Node * LinkedList_Node_p_new(void *data, size_t dataSize)
{
    LinkedList_Node * node = malloc(sizeof(*node));

    node->data = malloc(dataSize);
    memcpy(node->data, data, dataSize);

    node->prev = node->next = NULL;

    return node;
}

void LinkedList_Node_p_delete(LinkedList_Node * node)
{
    free(node->data);
    free(node);
}

LinkedList LinkedList_new(size_t elementSize)
{
    LinkedList list;
    list.p_elementSize = elementSize;
    list.p_nodeCount = 0;
    list.head = list.tail = NULL;
    return list;
}

void LinkedList_clear(LinkedList * list)
{
    LinkedList_Node * node = list->head;
    LinkedList_Node * next;

    while (node != NULL)
    {
        next = node->next;
        LinkedList_Node_p_delete(node);
        node = next;
    }

    *list = LinkedList_new(list->p_elementSize);
}

void LinkedList_pushBack(LinkedList * list, void * data)
{
    LinkedList_Node * node = LinkedList_Node_p_new(data, list->p_elementSize);

    if (list->p_nodeCount == 0)
    {
        list->head = list->tail = node;
    }
    else
    {
        list->tail->next = node;
        node->prev = list->tail;
        list->tail = node;
    }
    list->p_nodeCount += 1;
}
