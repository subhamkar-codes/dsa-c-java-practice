#include <stdio.h>
int linerSearch(int arr[],int size,int element){
for (int i = 0; i < size; i++)
{
    if (arr[i]==element)
    {
        return i;
    }
    
}
    return -1;

}

int main(){
    int arr[] ={1,3,5,56,4,323,5,4,54634,56,34};
    int element = 54634;
    int size = sizeof(arr)/sizeof(int);
    int searchIndex = linerSearch(arr,size,element);
    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0;
}