#include <stdio.h>
#include <stdlib.h>


typedef struct Node Node;

struct Node{

    int data;
    Node * prev , *next ;

};

Node * head = NULL;
Node * tail = NULL;



void Add(int data);
void Display();
void BubbleSort(int size);
int GetCount();
int getIndex(int data);


int main()
{
    Add(3);
    Add(1);
    //Add(9);
    Add(7);
    //Add(5);
    Add(8);
    Add(6);
    Add(2);
    Add(4);


    int size;
    printf("before sorting : \n");
    Display();
    BubbleSort(size);
    //int count = GetCount();
    printf("\nafter sorting: \n");
    Display();
    //printf("\n%d",count);
    int number;
    printf("\nenter a number to search : ");
    scanf("%d",&number);
    int search = binarySearch(number);
    if(search == -1){
        printf("\nthis number doesn't exist");
    }
    else{
        printf("\nthis number exist ");
    }

    return 0;
}
void Add(int data){

    Node * newNode = malloc(sizeof(Node));
    newNode-> data = data ;
    newNode-> prev = newNode->next = NULL;

    if(head == NULL){
        head = tail = newNode ;
    }
    else{
        tail->next = newNode ;
        newNode->prev = tail;
        tail = newNode;
    }

}
void Display(){
    Node * tmp = head;
    while(tmp != NULL){
        printf("%d\t",tmp -> data);
        tmp = tmp->next ;
    }

}

int GetCount(){
    int count;
    Node * tmp = head;
    while(tmp ->next!= NULL){
        count++;
        tmp = tmp->next;
    }
    return count;
}
void BubbleSort(int size){
    Node*tmp = NULL;
    Node*curr = NULL;
    int temp;
    for(curr=head ; curr->next != NULL ; curr=curr->next){
        for(tmp = curr->next ; tmp!= NULL ; tmp=tmp->next){
            if(tmp->data < curr->data){
                temp = tmp->data;
                tmp->data = curr->data;
                curr->data = temp;
            }
        }
    }
}

Node *middle (Node *start , Node *last){
    if(start == NULL){
        return NULL;
    }

    Node* slow = start;
    Node* fast = start->next;

    while(fast!= last){
        fast =fast->next;
        if(fast != last){
            slow=slow->next;
            fast=fast->next;
        }
    }
    return slow;
}
int binarySearch(int item){
    Node*min = head;
    Node*max= tail;


    while(max != min){
        Node *mid = middle(min,max);
        if(item == mid->data){
            return 1;
        }
        if(item > mid->data){
            min = mid->next;

        }
        else{
            max=mid;
        }

    }
    return -1;
}
