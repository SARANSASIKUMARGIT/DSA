#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

/* Saran SK */

/* Program to Left Rotate an Array by K positon - REVERSAL METHOD 
    TIME COMPLEXITY : O(2N) , SPACE COMPLEXITY : O(1) no extra space.
*/

void reverseArray(int *a,int start,int end)
{
    while(start<end)
    {
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        ++start;
        --end;
    }
}

void rotateArraybyK_Places(int *a,int n,int k)
{
    k=k%n;  //Because Number of rotation that is a mutliple of N will result in the same original array 
            // hence k mod n removes unneccesary number of rotations
    
    reverseArray(a,0,k-1);              //Reverse the first k portion of the array
    reverseArray(a,k,n-1);              //Reverse the portion from index k to n-1 index
    reverseArray(a,0,n-1);              //Finally, Reverse the entire array to get the K Left rotated array
    
}

void main()
{
    int a[]={9,3,6,1,10,7},k; 
    printf("Enter the value of k to rotate Left : ");
    scanf("%d",&k);                                    //Input K from User
    rotateArraybyK_Places(a,sizeof(a)/sizeof(int),k);      //Left Rotating the array by K places
    printf("\nAfter K Left Rotation : \n");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)            //Print the Left Rotated Array
        printf("%d  ",a[i]);
    printf("\n");

}
