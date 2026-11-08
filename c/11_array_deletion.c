#include <stdio.h>

// Traversal
void display(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

//Deletion
 int sortedDeletion(int arr[], int size, int element, int capacity, int index){ // int element, int capacity, NOT NACCERY
    if (index >= capacity )
    {
        return -1;
    }
    for (int i = index; i < size - 1; i++)
    {
        arr[i]= arr[i + 1];
    }
    arr[index] = element;
    return 1;
     

 }



int main(){
    int arr[100] = {7, 8, 12 , 27, 88};
    int size = 5; int element = 45;
     int index = 0;
   // display(arr , size);
    sortedDeletion(arr, size,element,100,index);
    size -= 1;
    display(arr,size);
    return 0;
}