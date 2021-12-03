
#include <stdio.h>


void printArray(int *a,int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


void selectionSort(int *a,int n){
int temp,indexOfMin;
    // n- 1 passes 
    printf("this is trial");
    for (int i = 0; i < n-1; i++)
    {
        indexOfMin = i;

        // find min. out of whole array left 
        for (int j = i+1; j < n; j++)
        {
            if(a[j] < a[indexOfMin]){
                indexOfMin = j;
            }

           

        }
         // then do swap as you find min. index element
             temp = a[i];
             a[i]=a[indexOfMin];
             a[indexOfMin] = temp;
    }
    
}


int main(){
int A[]={23,4,5,34,5};
int n=sizeof(A)/sizeof(int);
printArray(A,n);
selectionSort(A,n);
printArray(A,n);

return 0;
}




  // Input Array (There will be total n-1 passes. 5-1 = 4 in this case!)
    //  00  01  02  03  04
    // |03, 05, 02, 13, 12

    // After first pass
    //  00  01  02  03  04
    //  02,|05, 03, 13, 12

    // After second pass
    // 00  01  02  03  04
    // 02, 03,|05, 13, 12

    // After third pass
    // 00  01  02  03  04
    // 02, 03, 05,|13, 12

    // After fourth pass
    // 00  01  02  03  04
    // 02, 03, 05, 12,|13