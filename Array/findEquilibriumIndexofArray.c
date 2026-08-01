#include<stdio.h>

            /*  Saran SK  */
/* 
    Finding Equilibrium index in an array  OPTIMAL APPROACH
    Problem Statement: Given a 0-indexed integer array nums, find the leftmost equilibrium Index.

    Input: nums = [1, -1, 4]  
    Output: 2  
    Explanation:
        The sum of the numbers before index 2 is: 1 + (-1) = 0  
        The sum of the numbers after index 2 is: 0  
        --> Therefore, the output is index 2.

    TIME COMPLEXITY  : O(N) due to traversing the entire array to calculate the sum and find the equilibrium index ,
    SPACE COMPLEXITY : O(1) constant extra space for leftSum and rightSum variables,,,.
*/

int equilibriumIndex(int *a,int n)
{
    int sum=0,leftSum,rightSum;
    for(int i=0;i<n;++i)                //Calculating the sum of the array
        sum+=a[i];
    leftSum=0,rightSum=sum;             //Assing Left Sum and Right Sum value to 0 and Sum of all elements respectively
    for(int i=0;i<n;++i)
    {
        rightSum-=a[i];                 //Subtracting the current index value to the right sum for every iteration
        if(leftSum==rightSum)           // if both left and right sum are equal then the current index in the equilibrium index , return i
            return i;
        leftSum+=a[i];                  //adding the values left to the current index for every iteration
    }
    return -1;                          //If no equilibrium index is found, return -1
}

void main()
{
    int a[]={1,-1,4};

    printf("Equilibrium Index = %d \n",equilibriumIndex(a,sizeof(a)/sizeof(int)));  //Passing the array with it's size to the function to find the equilibrium index
}
