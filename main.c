#include "LinkedList.h"
#include "String.h"
#include <stdio.h>

int main() {

    LinkedList list = LinkedList_new(sizeof(int));

    int val = 5;
    LinkedList_pushBack(&list, &val);
    val = 6;
    LinkedList_pushBack(&list, &val);

    LinkedList_Node * n = list.head;

    while(n != NULL)
    {
        printf("%d\n", *(int *)n->data);
        n = n->next;
    }
    
    String s1, s2, s3;
    s1 = s2 = s3 = String_new();
    String_copyFromRaw(&s1, "Hello");
    String_copyFromRaw(&s2, " ");
    String_copyFromRaw(&s3, "World");
    
    LinkedList hw = LinkedList_new(sizeof(String));
    
    LinkedList_pushBack(&hw, &s1);
    LinkedList_pushBack(&hw, &s2);
    LinkedList_pushBack(&hw, &s3);
    
    n = hw.head;
    
    while (n != NULL)
    {
        printf("%s", ((String *)n->data)->buf);
        String_dealloc(n->data);
        n = n->next;
    }
    
    return 0;
}
