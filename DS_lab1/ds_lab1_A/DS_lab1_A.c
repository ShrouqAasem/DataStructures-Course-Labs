
#ifndef LINKED_LIST_HEADER_INCLUDED
#define LINKED_LIST_HEADER_INCLUDED

typedef struct Node Node;
struct Node
{
    int data;
    Node *prev, *next;
};
typedef struct LinkedList
{
    Node *head;
    Node *tail;
} LinkedList;


int GetCount(LinkedList * ls)
{
    Node *current = ls->head;
    int counter = 0;
    while (current != NULL)
    {
        current = current->next;
        counter++;
    }
    return counter;
}
void *GetDataByIndex(LinkedList * ls, int index)
{
    Node *current = ls->head;

    for(int i =0; i<GetCount(ls);i++){
        if(index == i){
            return current->data;
        }
        current = current->next;
    }
}

#endif

