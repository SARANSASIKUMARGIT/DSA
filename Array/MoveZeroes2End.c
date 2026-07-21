#include<stdio.h>
#include<stdlib.h>

/* Saran SK */

/* Program to Move All Zeros 0 in the array to the end (by pointer approach)
    TIME COMPLEXITY : O(N) depends on number of zeros in the array, SPACE COMPLEXITY : O(1) no extra space.
*/

void moveZero2End(int *a,int n)
{
    int pointer=0;         //Keep track of index where the non-zero elements are to be copied , pause when a[i]==0
    for(int i=0;i<n;++i)
    {       
        //Pointer does not get incremented when a[i] == 0 , to assign upcoming non-zero element to that pointer index.
        if(a[i]!=0)
        {
            a[pointer]=a[i];
            ++pointer;          // alternative : a[pointer++] = a[i]
        }
    }
    
    for(int i=pointer;i<n;++i)      //Assigning Zero 0 to the last portion (number of zeroes) in the array
        a[i]=0;
}

void main()
{
    int a[]={9,5,0,3,6,1,2,0,10,7};

    moveZero2End(a,sizeof(a)/sizeof(int));
    for(int i=0;i<sizeof(a)/sizeof(int);++i)            //Print the Left Rotated Array
        printf("%d  ",a[i]);
    printf("\n");

}
