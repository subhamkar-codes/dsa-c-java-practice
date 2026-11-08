 #include <stdio.h>
 #include <stdlib.h>
 struct Node{
    int data;
    struct Node * next;
 };
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {

        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
        struct Node *InsertAtFirst(struct Node *head, int data){
            struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
            ptr ->next = head; 
            ptr -> data = data;
            return ptr;

        }


        struct Node *InsertAtBetween(struct Node *head, int data , int index){
            struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
            struct Node* p = head;
            int i = 0;
            while (i != index-1)
            {
                p = p->next;
                i++;
            }
            ptr ->data = data;
            ptr ->next = p ->next;
            p-> next = ptr;
            return head;
        }


        struct Node *InsertAtEnd(struct Node *head, int data){
            struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
            ptr->data = data;
            struct Node* p = head;

            while (p->next != NULL)
            {
               p = p->next;
            }

            p->next = ptr;
            ptr->next = NULL;
            return head;           
        }

        struct Node *InsertAfterNode(struct Node *head,struct Node *prevNode, int data){
            struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
            ptr->data = data;

            ptr->next = prevNode->next;
            prevNode->next = ptr;
            
            return head;           
        }



 int main(){
     struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    forth = (struct Node *)malloc(sizeof(struct Node));
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;
    
    third->data = 15;
    third->next = forth;

    forth->data = 65;
    forth->next = NULL;

    printf("linkedlist Before insertion\n");
    LinkedListTraversal(head);

    printf("\n");
    printf("linkedlist After insertion at the Start\n");
    head = InsertAtFirst(head, 56);
    LinkedListTraversal(head);

    printf("\n");
    printf("linkedlist After insertion at the middle\n");
    head = InsertAtBetween(head , 49 , 3);
    LinkedListTraversal(head);

    printf("\n");
    printf("linkedlist After insertion at the End\n");
    head = InsertAtEnd(head, 99);
    LinkedListTraversal(head);

    printf("\n");
    printf("linkedlist After insertion at the End\n");
    head = InsertAfterNode(head, second,37);
    LinkedListTraversal(head);

    return 0;
    
 }