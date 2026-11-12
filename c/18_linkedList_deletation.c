#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {

        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// CASE 1: deleting the first NODE from the linked list;
struct Node* deletefirst(struct Node* head){
    struct Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

//CASE 2: deleting at the index
struct Node* deleteAtIndex(struct Node* head, int index){
        struct Node*p = head;
        struct Node* q = head -> next; 
        for (size_t i = 0; i < index-1; i++)
        {
            p = p-> next;
            q = q -> next;
        }
        p ->next = q ->next;
        free(q);
        return head;
}

//CASE 3: delete the last node;
struct Node*  deleteLast(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
     while (q->next != NULL)
     {
        p = p -> next;
        q = q-> next;
     }
     p-> next = q -> next;
     free(q);
     return head;

     
}


//CASE 4: deleting NODE WITH A GIVEN VALUE
struct Node* deleteWithValue(struct Node* head, int value){
        struct Node*p = head;
        struct Node* q = head -> next; 
      while (q ->data != value && q -> next != NULL){
        p = p -> next;
        q = q -> next;
      }
    if (q->data == value){
        p ->next = q ->next;
        free(q);}
        return head;
}


int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    
    head->data = 4;
    head->next = second;

    second->data = 3;
    second->next = third;
    
    third->data = 8;
    third->next = forth;

    forth->data = 1;
    forth->next = NULL;

    printf("LinkedList before deletion\n");
    LinkedListTraversal(head);

// deleting the first node    
// head = deletefirst(head);

//deleting at a INDEX 
// head = deleteAtIndex(head,2);

//deleting the last node
// head = deleteLast(head);

//deleting a node with a value
head = deleteWithValue(head,8);

    printf("LinkedList after deletion\n");
    LinkedListTraversal(head);

    return 0;
}