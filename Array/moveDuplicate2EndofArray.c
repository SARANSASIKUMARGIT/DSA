#include<stdio.h>
#include<stdlib.h>

/* Saran SK */

/* Program to move duplicate elements to the end of the array (by TWO POINTER APPROACH)
    TIME COMPLEXITY : O(N) , SPACE COMPLEXITY : O(1) no extra space.
*/

void moveDuplicate2EndofArray(int *a,int n)
{
    int pointer=0;                          //Pointer to store index to copy the next first original value
    for(int i=0;i<n;++i)
    {
        a[pointer++]=a[i];                  //Incrementing the pointer when a first original value is found
        while(i<n-1 && a[i]==a[i+1])        //Incrementing the index i and moving forward until the duplicates are completed traversed
            ++i;
    }
    for(int i=pointer;i<n;++i)              //Setting all the elements from index pointer to n-1 to 0 (duplicate values)
        a[i]=0;
}

void main()
{
    int a[]={1,1,2,3,3,3,4,5,5,5,5,7};

    moveDuplicate2EndofArray(a,sizeof(a)/sizeof(int));

    for(int i=0;i<sizeof(a)/sizeof(int);++i)            //Print the Array
        printf("%d  ",a[i]);
    printf("\n");

}
