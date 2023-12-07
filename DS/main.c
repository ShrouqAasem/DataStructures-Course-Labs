
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
}   LinkedList;

    void Add(LinkedList * ls, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    if(ls->head == NULL)
    {
        newNode->index = 0;
        ls->head = newNode;
        ls->tail = newNode;
        ls->head->index = 0;
        ls->tail->index = 0;
    }
    else
    {
        ls->tail->next = newNode;
        newNode->prev = ls->tail;
        ls->tail = newNode;
    }
    newNode->index = ls->tail->index;
}

   void Display(LinkedList * ls)
{
    Node *current = ls->head;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
}

