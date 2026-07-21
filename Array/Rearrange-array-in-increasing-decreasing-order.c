#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

/* Saran SK */

/*
    Rearrange array in increasing-decreasing order
    Problem Statement: Rearrange a given array such that the first half is arranged in increasing order, and the second half is arranged in decreasing order
    Example: Input: {1,9,7,11,6,1} Output: {1,1,6,11,9,7}
*/

//Sort array in Ascending Order
void sortArray(int *a,int n)
{
    int temp;
    for(int i=0;i<n-1;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void reverseArray(int *a,int start,int end)  //Function to reverse an array
{
    --end;
    int temp;
    while(start<end)
    {
        temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        ++start;
        --end;
    }
}
 
void main()
{ 
    int a[]={33,98,32,4,12,54,3,1,54};
    int n = sizeof(a)/sizeof(int);

    sortArray(a,n);                 //Sort the entire array in ascending order
    reverseArray(a,n/2,n);          //Reverse the second half of the array  to make it in descending order

    for(int i=0;i<n;++i)
        printf("%d  ",a[i]);        //Print the sorted array
        printf("\n");
}
