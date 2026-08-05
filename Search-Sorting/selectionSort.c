#include<stdio.h>
#include<math.h>
#include<stdbool.h>

        /*    Saran SK     */

/*
    C program for performing Selection Sort Algorithm,
    Selection Sort algorithm traverse from 0 to n-1 element of the array,
    at every iteration it found the smallest element's index with an inner loop of range i+1 to n-1 ,
    then swap the i'th element with the element at index minIndex. Thus , Array is sorted.

    TIME COMPLEXITY  : O(N^2)    due to nested loop,
    SPACE COMPLEXITY : O(1)      only constant extra space
*/

void selectionSort(int a[],int n)
{
    int minIndex;                       //variable to store the index of the minimum value of the array
    for(int i=0;i<n;++i)                //traversing the array from index 0 to n-1
    {
        minIndex=i;                     //initially, assuming that i'th element is the smallest element
        for(int j=i+1;j<n;++j)          //iterating the inner loop from i+1 to n-1 to find the smallest element in that range
        {
            if(a[j]<a[minIndex])        //if the current element is less than the minimum element, then change the minIndex value to current index
                minIndex=j;
        }
        int temp=a[i];                  //after the inner loop, swap the i'th element with the minIndex element found at the traversal of the inner loop
        a[i]=a[minIndex];
        a[minIndex]=temp;
    }
}

void main()
{
    int a[]={10,3,43,23,4,8,1,12};

    printf("Before Selection Sort : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");

    selectionSort(a,sizeof(a)/sizeof(int));                 //calling the selection sort function

    printf("After Selection Sort  : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");


}
