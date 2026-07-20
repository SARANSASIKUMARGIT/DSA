#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
    /* Saran SK */
int* findSecondSmallestAndLargest(int *arr,int n)
{
    if(n<2)         //if array size is less than 2 then return NULL (no second largest and smallest value possible)
        return NULL;
    int firstSmallest=INT_MAX,secondSmallest=INT_MAX,firstLargest=INT_MIN,secondLargest=INT_MIN;      //Initializing smallest variable with largest value INT_MAX and vice versa
    for(int i=0;i<n;++i)
    {
        if(arr[i]<firstSmallest)            
        {
            secondSmallest=firstSmallest;           //moving firstSmallest value to secondSmallest and copying arr[i] to firstLargest
            firstSmallest=arr[i];
        }
        else if(arr[i]<secondSmallest && arr[i]!=firstSmallest)
            secondSmallest=arr[i];                  //copying value to secondSmallest if value if second smallest
        if(arr[i]>firstLargest)
        {
            secondLargest=firstLargest;             //moving firstLargest value to secondLargest and copying arr[i] to firstLargest
            firstLargest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]!=firstLargest)
            secondLargest=arr[i];                   //copying value to secondLargest if value if second largest
    }
    if(secondLargest!=INT_MIN && secondSmallest!=INT_MAX)
    {
        int *secondSmallestAndLargest=(int*)malloc(2*sizeof(int));  //allocating memory for secondSmallest and secondLargest
        *(secondSmallestAndLargest)=secondSmallest;   //storing secondSmallest value in the allocated memory
        *(secondSmallestAndLargest+1)=secondLargest;  //storing secondLargest value in the allocated memory
        return secondSmallestAndLargest;      //returning the memory address of the integer array allocated dynamically
    }
    return NULL;        //returning NULL if no second smallest and largest element found
}



void main()
{
    int a[]={90,0,90,0};
    int *ptr=findSecondSmallestAndLargest(a,sizeof(a)/sizeof(int));
    if(ptr==NULL)
    printf("No Second Smallest and Largest Element Found \n");
    if(ptr)
        printf("Second Smallest Number : %d \nSecond Largest Number : %d\n",ptr[0],ptr[1]); //printing the second smallest and largest element
    free(ptr);      //freeing the allocated memory

    
}
