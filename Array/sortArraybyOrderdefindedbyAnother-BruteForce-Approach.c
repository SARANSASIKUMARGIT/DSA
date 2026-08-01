#include<stdio.h>

/*    Saran SK    */

/*
    Problem Statement : Sort an array according to the order defined by another array. BRUTE FORCE APPROACH
    Input Array 1 (arr1): [2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8]
    Input Array 2 (arr2): [2, 1, 8, 3] (defines the custom sorting sequence)
    Output Array: [2, 2, 1, 1, 8, 8, 3, 5, 6, 7, 9]

    TIME COMPLEXITY  : O(N1*N2 + N1)   as we use nested loops and traversing the rest of the array to find the duplicate of the current element , 
    SPACE COMPLEXITY : O(N)            extra space for array to store rank of each element
*/

void bubbleSortbyRank(int *a,int* rankArray,int n)
{
    int temp;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n-1-i;++j)
        {
            if(rankArray[j]==rankArray[j+1])        //if both the rank of adjacent elements are same, the larger element is swaped in the original array
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
            else if(rankArray[j]>rankArray[j+1])        // if rank of j th element is greater ,then both the elements swaps their position to maintain sorting by rank 
            {
                temp=a[j];                              //both their rank and value are swapped to sort them in ascending
                a[j]=a[j+1];
                a[j+1]=temp;
                temp=rankArray[j];
                rankArray[j]=rankArray[j+1];
                rankArray[j+1]=temp;
            }
        }
    }
}


void sortArrayByOrderDefinedByAnotherArray(int* a,int n1,int* b,int n2)
{
    int index=-1,rank[n1];
    for(int i=0;i<n1;++i)                   //initially assigning the rank of all elements to -1 as they are found yet
        rank[i]=-1;
    for(int i=0;i<n1;++i)
    {
        if(rank[i]==-1)                     // if rank of an element is -1 it means it is found for the first time 
        {
            index=-1;
            for(int j=0;j<n2;++j)           //Finding the position(rank) of the element in the secondArray
            {
                if(a[i]==b[j])              //the index of the element in arr1 in arr2 is its rank
                {
                    index=j;
                    break;
                }
            }
            for(int j=i;j<n1;++j)
            {
                if(a[i]==a[j])
                   rank[j]= (index==-1)? (n2+1): (index+1);     //assigning the rank of the duplicates of current element with its rank , which is sizeof arr2 is no element is found in the arr2
            }
        }
    }   
    bubbleSortbyRank(a,rank,n1);            //sort the array 'a' by the rank in the rankArray.
}

void main()
{
    int a[]={2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8},b[]={2, 1, 8, 3};
    
    sortArrayByOrderDefinedByAnotherArray(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int));   //Passing both the arrays to function to sort by the order defined by the second Array
    
    for(int i=0;i<sizeof(a)/sizeof(int);++i)   //Printing the final Sorted Array
        printf("%d ",a[i]);
    printf("\n");    
}
