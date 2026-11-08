#include <stdio.h>
int BinarySearch(int arr[],int size,int element){
    int low, mid , high;
    low = 0;
    high = size -1;
    
    while (low<=high)
    {
    
   
    
    mid = (low + high)/2;
    if (arr[mid] == element)
    {
        return mid;
    }
    if (arr[mid]<element)
    {
        low = mid +1;
    }
    else{
        high = mid -1;
    }
    
     }

     return -1;

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
    int arr[] ={1,3,5,56,64,73,123,225,444,54634};
    int element = 444;
    int size = sizeof(arr)/sizeof(int);
    int searchIndex = BinarySearch(arr,size,element);
    printf("The element %d was found at index %d \n",element,searchIndex);
    return 0;
}