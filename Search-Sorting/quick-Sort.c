#include<stdio.h>
#include<stdlib.h>  

        /*    Saran SK     */

/*
  C Program that implements Quick Sort Algorithm for Sorting the Array,
   Quick Sort is Most Efficient Sorting algorithm , which selects an element in the array and \
    places the elements in it's appropriate position where all the elements to it's left are less than it and \
    all the elements to the right of it are greater than it. 
    Then the both subarrays are sorted in the same method by recursion by dividing them with partitionIndex

    Time Complexity of Quick Sort is Same as Merge Sort O(N logN) but,
    Space Complexity of Quick Sort is O(1) as it works on the original array ,then using an extra array like Merge Sort where Space Complexity is O(N),
    Therefore , Quick Sort is the most efficient Sorting algorithm and used in Sorting methods of Many Programming Language's Library
*/

void swap(int *a,int *b)            //function to swap values in two given memory addresses
{
    int c=*a;
    *a=*b;
    *b=c;
}

int findPartitionIndex(int* arr,int low,int high)                   //function to find the partitionIndex (appropriate postion) of the pivotElement
{
    if(low<high)
    {
        int i=low, j=high, pivotIndex= rand() % (high-low+1);                     //selecting pivot index at random 
        swap(arr+low,arr+pivotIndex);                                             //swapping the element at pivotIndex with the first element of the subarray
        int pivotElement = arr[low];                                              //assigining the pivotElement as the firstElement of the subarray
        while(i<j)
        {
            //finding the greatest element in the right of pivot element
            while(i<=high && arr[i]<=pivotElement)
                ++i;
            //finding the element that is smallest than pivot element from the end index of the sub array
            while(j>=low && arr[j]>pivotElement)
                --j;

            if(i<j)                             //if smallest element index is less than the greatest element index , it means still the elements in the range of index are not in sorted order
                swap(arr+i,arr+j);
        }
        swap(arr+low,arr+j);                    //after end of the loop i is > j, it means the smallest element is left to the greatest element of pivot,
                                                //then if pivotElement is swapped with element with smallest element found, then all the elements left to the pivotElement is will be less than it, and all the elements right to the pivotElement are greater than it.
        return j;           //returning the partitioning index, to divide the array into two sub arrays
    }
    return -1;          //if low>high , invalid range
}

void quickSort(int* arr,int low,int high)               
{
    if(low<high)
    {
        int partitionIndex=findPartitionIndex(arr,low,high);            //finding the partitionIndex
        quickSort(arr,low,partitionIndex-1);                            //Spliting the array as two subarray by the partition Index
        quickSort(arr,partitionIndex+1,high);
    }
}

int main()
{
    int n,*arr=NULL;
    printf("Enter the number of elements of array : ");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));                    //dynamic memory allocation of array at runtime
    for(int i=0;i<n;++i)
    {
        printf("Enter value %d : ",i);
        scanf("%d",arr+i);
    }
    
    if(n>0)
    {
        printf("Array Before Sorting : ");
        for(int i=0;i<n;++i)
            printf("%d ",*(arr+i));

        quickSort(arr,0,n-1);                   //calling quickSort()

        printf("\nArray after Sorting : ");             //printing the sorted array after quickSort()
        for(int i=0;i<n;++i)
            printf("%d ",*(arr+i));
        printf("\n");
    }
    else
    printf("Array is Empty \n");

    free(arr);          //deallocating memory allocated at runtime for array

    return 0;

}



