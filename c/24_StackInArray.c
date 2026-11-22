#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *) malloc (s.size* sizeof(int));

    struct stack *s;
    s->size = 3;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

// Pushing a element manually...
s -> arr[0] = 7;
s->top++;

s->arr[1] = 11;
s->top++;

s->arr [2] = 12;
s->top++;







// Check if the stack is empty........
if (isEmpty(s))
{
printf("The Stack is empty\n");
}
else{
    printf("The stack is not empty\n");
}

if (isFull(s))
{
    printf("The stack is full\n");
}
else{
    printf("The stack is not full\n");
}



    return 0;
}