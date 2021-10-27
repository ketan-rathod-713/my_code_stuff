#include <stdio.h>
#include <conio.h>

// bubble sort
//input -- 7 11 9 2 17 4
// compare two at A time , if not in sorting order then swap else take as it is
// 1st pass -- 7 9 11 2 17 4 // 1,2
//          --7 9 2 11 17 4 //2,3
//          --7 9 2 11 17 4   // 3,4 and so on
//          --7 9 2 11 4 17 -- first pass done and largest element is on right side

//second pass -- 7 9 2 11 4 17 // 0 ,1  //4 possible swaps
//7 2 9 11 4 17
//7 2 9 11 4 17
//7 2 9 4 11 17 // now last two elements done and soo onn

// 4th pass gives 2 4 7 9 11 17 // 2 possible swaps
//5th pass gives 2 4 7 9 11 17 // it will give sorted array as length of array is 6 // 1 possible swap

// total no of comparison = 1 +2 + 3 + 4 + .... + (n-1) == n(n-1)/2 == O(n^2)
// this is stable sorting algo as order is same as that of input array
// this is not adaptave algo. // what it will do if given sorted ?
// why bubble sort --  hydrogen balloon -- ligher and heivier elements move in different direction that's why the name is this

void bubbleSort(int *A, int n){
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n-1; i++)
    {   
          printf("working on pass no. %d\n",i+1);
        isSorted = 1;
        for (int j = 0; j < n-1-i; j++)
        {
             if(A[j]>A[j+1]){
                 
                 temp = A[j];
                 A[j] = A[j+1];
                 A[j+1] = temp;
                isSorted = 0;
             }
        }
        
        if(isSorted){
            return;
        }
    }
    
}

void printArray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main()
{
//    int A[]={3,122,34,45,99,12};
int A[]={1,2,3,4,5};
   int n = sizeof(A)/sizeof(int);
   printArray(A,n);
   bubbleSort(A,n);
   printArray(A,n);
    return 0;
}