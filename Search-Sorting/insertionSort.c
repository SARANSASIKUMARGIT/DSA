#include<stdio.h>
#include<math.h>
#include<stdbool.h>

        /*    Saran SK     */
/*
    C Program to sort an array using Insertion Sorting Algorithm,
    An Insertion Sorting Algorithm performs sorting by taking the element of current index of each iteration and 
    inserts it into the position where its previous element is less than or equal to it.

    TIME COMPLEXITY : Best Case : O(N) for already Sorted Array , Worst Case : O(N^2) ,
    SPACE COMPLEXITY : O(1)  only constant extra memory space is used.

*/

void insertionSort(int a[],int n)
{
    for(int i=0;i<n;++i)                        //Traversing from index 0 to n-1 
    {
        int j=i;                                //select the current index of the iteration
        while(j>0 && a[j-1]>a[j])               //while the previous element is greater than the current element and pointer to the element to compare does not become 0
        {
            int temp=a[j-1];                    //swapping the current element with the previous larger element
            a[j-1]=a[j];
            a[j]=temp;
            j--;
        }
    }
}

void main()
{
    int a[]={10,3,43,23,4,8,1,12};

    printf("Before Insertion Sort : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");

    insertionSort(a,sizeof(a)/sizeof(int));               //calling the inserionSort function with array,size of the array

    printf("After Insertion Sort : ");                          //Printing the sorted array after insertionSort
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");


}
