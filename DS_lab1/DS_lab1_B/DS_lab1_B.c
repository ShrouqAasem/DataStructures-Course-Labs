void InsertAfter(LinkedList * ls, int data, int AfterData)
{
    Node *node = GetNodeByData(ls, AfterData);
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
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
                Add(ls, data);
                node->next->index = node->index + 1;
            }
            else
            {
                Node *prev = node->prev;
                Node *next = node->next;

                node->next = newNode;
                node->next->index = node->index + 1;

                newNode->prev = node;
                newNode->next = next;

                newNode->index = node->index+1;
                int isAfterEdit = 0;
                Node *current = newNode;
                while (current != NULL)
                {
                    if(isAfterEdit == 1)
                    {
                        current->index++;
                    }
                    if(newNode->data == current->data)
                    {
                        isAfterEdit = 1;
                    }
                    current = current->next;
                }
            }
        }
        else if(node == ls->tail)
        {
            Add(ls, data);
                node->next->index = node->index + 1;
        }
        else
        {
            Node *prev = node->prev;
            Node *next = node->next;

            node->next = newNode;
            newNode->prev = node;
            newNode->next = next;


            node->next->index = node->index + 1;
            int isAfterEdit = 0;
            Node *current = newNode;
            while (current != NULL)
            {
                if(isAfterEdit == 1)
                {
                    current->index++;
                }
                if(newNode->data == current->data)
                {
                    isAfterEdit = 1;
                }
                current = current->next;
            }.
        }
    }
    }
