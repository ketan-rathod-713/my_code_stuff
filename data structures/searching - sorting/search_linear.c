#include<stdio.h>
#include<conio.h>

// linear search -- search linearly --full array traversal , sorted + unsorted 
// O(n)
int linearSearch(int arr[], int size , int element){

    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
        }
    }
    return -1;
}

int main(){

int arr[]={1,4,5,6,7,8,3};
int size = sizeof(arr)/sizeof(int);
int searchIndex = linearSearch(arr,size,5);

return 0;
}