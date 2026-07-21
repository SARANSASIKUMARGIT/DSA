#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Saran SK */

/* Program to find Repeating Elements in an array
    TIME COMPLEXITY : O(N^2) because of bubble sort (worst case), 
    SPACE COMPLEXITY : O(1) no extra space.

    NOTE: This Program is a BETTER APPROACH, The OPTIMAL APPROACH can be achieved by Hash Maping.
*/

void bubbleSort(int *a,int n)           //Bubble sorting to sort the array (Better Approach)
{
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(n-i)-1;++j)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void displayRepeatingElementsinArray(int *a,int n)
{
    // Better Approach
    bubbleSort(a,n); 
    for(int i=0;i<n-1;++i)
    {
        if(a[i]!=a[i+1])        //Skipping the non-repeating value
            continue;
        printf("%d ",a[i]);     //Printing the First Repeating Value of Series
        while(i<n-1 && a[i]==a[i+1])   //Skipping all other following duplicates
            ++i;
    }
}

void main()
{
    int a[]={1,1,63,43,1,43,65,9,65,98,11,3,7};
    displayRepeatingElementsinArray(a,sizeof(a)/sizeof(int));  //Passing the array and its size as parameter.

}
