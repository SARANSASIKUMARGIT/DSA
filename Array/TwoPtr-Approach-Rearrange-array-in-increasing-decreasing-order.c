#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

/* Saran SK */

/*
    Rearrange array in increasing-decreasing order
    Problem Statement: Rearrange a given array such that the first half is arranged in increasing order, and the second half is arranged in decreasing order
    Example: Input: {1,9,7,11,6,1} Output: {1,1,6,11,9,7}
*/

//Two Pointer Approach
void sortFirstHalfAscendingSecondHalfDescending(int *a,int n)
{
    int minIndex=-1,maxIndex=-1,half1Start=0,half2Start=(n/2),minValue=INT_MAX,maxValue=INT_MIN;
    while(half1Start<n/2 && half2Start<n)
    {
        minValue=INT_MAX;
        maxValue=INT_MIN;
        for(int i=half1Start;i<n/2;++i)
        {
            if(a[i]<minValue)
            {
                minValue=a[i];
                minIndex=i;
            }
            if(a[i]>maxValue)
            {
                maxValue=a[i];
                maxIndex=i;
            }
        }
        for(int i=half2Start;i<n;++i)
        {
            if(a[i]<minValue)
            {
                minValue=a[i];
                minIndex=i;
            }
            if(a[i]>maxValue)
            {
                maxValue=a[i];
                maxIndex=i;
            }
        }
        if(half1Start==maxIndex)
            maxIndex=minIndex;
        // printf("Min : %d \t Max : %d\n",minValue,maxValue);
        int temp=a[half1Start];
        a[half1Start]=a[minIndex];
        a[minIndex]=temp;
        temp=a[half2Start];
        a[half2Start]=a[maxIndex];
        a[maxIndex]=temp;
        ++half1Start;
        ++half2Start;
    }
}

void main()
{
    int a[]={9,3,6,1,10,7}; //1,3,6,10,9,7
    sortFirstHalfAscendingSecondHalfDescending(a,sizeof(a)/sizeof(int));
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
    printf("%d  ",a[i]);
    printf("\n");
    

    
}
