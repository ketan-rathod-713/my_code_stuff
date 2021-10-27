#include<stdio.h>
#include<conio.h>

// if array is sorted 
// binary search -- array must be sorted and then just like dictionary and find
// low mid and high track all three , mid is highest int. of low + mid / 2
//change low and mid each time if not found 
// check each time element found or not 
//O(log n)
int binarySearch(int arr[],int size,int element){
    
    int low = 0, mid, high = size - 1;
    mid = (low +high)/2; 

    //start searching
    while(low<=high){
    if(arr[mid]==element){
        return mid;
    }
    if(arr[mid]<element){
        low =  mid + 1;
    }
    if(arr[mid]>element){
        high = mid - 1;
    }
    }
    return -1;  // not returned in loop so element not found
}

int main(){
int arr[]={1,2,3,6,7,8,9};
int searchIndex = binarySearch(arr,7,4);
printf("the element found at %d",searchIndex);

return 0;
}