#include<stdio.h>
#include<stdlib.h>  
#include<stdbool.h>

        /*    Saran SK     */

/*
    C Program to check whether an Array is a Subset or not ?
    An array is a subset of another array if all the elements in the arr1 are present in the arr2 .

    This program is an BRUTE-FORCE Approach which selects each element from the arr1 and traverse through the arr2 to check whether it exists in the arr2,
    The verified element are moved to the front of the arr2 by using a pointer starting from index 0 and incrementing the pointer for every element found matching with element in arr1 \
    by swapping the variable at the found index with the pointer index and incrementing the pointer by 1.
    If any element in arr1 is not found in arr2 then arr1 is not a subset of arr2 therefore return false.

    After all the iteration are completed successfully , then it means all elements in arr1 are found to be in arr2 ,
    Therefore , Return True 

    TIME COMPLEXITY  : O(N1 * N2) due to nested loop,
    SPACE COMPLEXITY : O(1) only constant space .
*/


bool isSubsetArray(int *arr1,int n1,int *arr2, int n2)
{
    int pointer_arr2=0,found_index;
    bool isElementFound = false;

    for(int i=0;i<n1;++i)
    {
        isElementFound=false;
        for(int j=pointer_arr2;j<n2;++j)
        {
            if(arr1[i]==arr2[j])
            {
                found_index = j;
                isElementFound=true;
                break;
            }
        }
        if(isElementFound)
        {
            int temp=arr2[pointer_arr2];
            arr2[pointer_arr2++]=arr2[found_index];
            arr2[found_index]=temp;
        }
        else
            return false;
    }
    return true;
}


void inputArray(int *arr,int n)
{
    //Function to input the array
    for(int i=0;i<n;++i)
    {
        printf("Enter value of Element %d : ",i);
        scanf("%d",arr+i);
    }
}

int main()
{
    int n1,n2;
    printf("\nNOTE : Size of Arr1 must be less than or equal to the Size of Arr2 \n");
    printf("\nEnter the size of Arr1 (Array to be Verified , Subset Array) : ");
    scanf("%d",&n1);
    printf("Enter the size of Arr2 (Parent Array) : ");
    scanf("%d",&n2);
    if(n1>n2)               //if sizeof(arr1) > sizeof(arr2)
    {
        printf("The Arr1 (Child Array) size cannot be greater than the Arr2 (Parent Array)\n");
        return 1;
    }

    int *arr1=(int*)malloc(n1*sizeof(int));          //Allocating memory at runtime for arr1 & arr2
    int *arr2=(int*)malloc(n2*sizeof(int));
    if(arr1==NULL || arr2==NULL)                    //if memory allocation failed
    {
        printf("Dynamic Memory Allocation failed for Array \n");
        return 1;
    }

    inputArray(arr1,n1);                    //Inputing both the array from the user as input
    inputArray(arr2,n2);

    if(isSubsetArray(arr1,n1,arr2,n2))
        printf("Arr1 is a Subset of Arr2\n");
    else
        printf("Arr1 is not a Subset of Arr2\n");

    free(arr1);        //deallocating memory of dynamic arrays
    free(arr2);


    return 0;

}



