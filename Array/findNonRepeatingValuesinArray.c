#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Saran SK */

/* Program to find Non-Repeating Elements in an array
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

void displayNonRepeatingElementsinArray(int *a,int n)
{
    // Better Approach
    bubbleSort(a,n); 
    for(int i=0;i<n-1;++i)
    {
        if(a[i]!=a[i+1])       //Checking whether two adjacent elements are same
            printf("%d ",a[i]);  //Printing the Unique Value
        while(i<n-1 && a[i]==a[i+1])  //Loop to skip duplicate elements
            ++i;
    }
    if(n>1 && a[n-1]!=a[n-2])//Checking the last element which is not verified in the loop
        printf("%d ",a[n-1]);
    printf("\n");
}

void main()
{
    int a[]={1,1,63,43,1,43,65,9,98,11,3,7};
    displayNonRepeatingElementsinArray(a,sizeof(a)/sizeof(int));

}
