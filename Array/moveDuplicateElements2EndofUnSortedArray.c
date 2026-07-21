#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Saran SK */

/* Program to move duplicate elements to the end of the UnSorted array (by TWO POINTER APPROACH)
    TIME COMPLEXITY : O(N^2) because of nested loop (worst case), 
    SPACE COMPLEXITY : O(N) cause we use extra space for visited array to keep track whether a value is found before.
*/

void moveDuplicates2EndofUnsortedArray(int *a,int n)
{
    int pointer=0;
    bool visited[n];            // boolean array to keep track whether an element is visited before to move on 
    for(int i=0;i<n;++i)
        visited[i]=false;       //initially all elements are assigned as false (not visited)
    for(int i=0;i<n;++i)
    {
        if(visited[i])
            continue;           //if element is already visited move on to the next iteration (time save)
        a[pointer++]=a[i];      //incrementing the pointer to copy the next first original value
        visited[i]=true;
        for(int j=i+1;j<n;++j)
        {
            if(a[i]==a[j])
                visited[j]=true;        //if duplicate of an element found, mark it as "true" (visited)
        }
    }
    for(int i=pointer;i<n;++i)          //set all duplicate element at the end of the array to 0
        a[i]=0;
}

void main()
{
    int a[]={1,1,2,3,3,3,4,5,5,5,5,7};

    moveDuplicates2EndofUnsortedArray(a,sizeof(a)/sizeof(int));

    for(int i=0;i<sizeof(a)/sizeof(int);++i)            //Print the Array
        printf("%d  ",a[i]);
    printf("\n");

}
