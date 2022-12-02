Node *GetNodeByData(LinkedList * ls, int data)
{
    Node *current = ls->head;
    while (current != NULL)
    {
        if(data == current->data)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void DeleteNode(LinkedList * ls, int data)
{
    Node *node = GetNodeByData(ls, data);
    if(node == NULL)
    {
        return;
    }
    else
    {
        if(node == ls->head)
        {
            if(node == ls->tail)
            {
                ls->head = ls->tail = NULL;
            }
            else
            {
                ls->head = ls->head->next;
                ls->head->prev = NULL;
            }
        }
        else if(node == ls->tail)
        {
            ls->tail = ls->tail->prev;
            ls->tail->next = NULL;
        }
        else
        {
            Node *prev = node->prev;
            Node *next = node->next;
            prev->next = next;
            next->prev = prev;
        }
        free(node);
    }
}
