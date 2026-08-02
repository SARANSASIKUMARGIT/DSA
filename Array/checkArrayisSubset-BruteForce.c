#include<stdio.h>
#include<stdbool.h>

/*    Saran SK    */

/*
    Check if array is subset of another array   BRUTE FORCE APPROACH
    Problem Statement: Given arr1[] and arr2[], we need to find whether arr1[] is a subset of arr2[]. An array is called a subset of another if all of its elements are present in the other array..

    Example 1:
    Input:   arr1[]= [1,3,4,5,2]
             arr2[]= [2,4,3,1,7,5,15]
    Output:  arr1[] is a subset of arr2[]

    Time Complexity  : O(N1 * N2) as nested loop is used,
    Space Complexity : O(1)       only constant extra space for temporary variables
*/

bool isSubsetArray(int *a,int n1, int *b, int n2)   
{
    if(n1>n2) return false;     //if array1 is larger than array2 , then it is obvious that array1 is not a subset of array2
    bool isFound=false;         //Flag variable to check whether the element of a1 is found in a2
    int temp,swapIndex;         //Temporary variable for storing value at swapping and swapIndex of element to swap and store temporary value
    for(int i=0;i<n1;++i)
    {
        isFound=false;          //Reseting the flag for each element
        for(int j=i;j<n2;++j)   //starting for i'th index of array2 because already found elements are moved to the left of i'th index
        {
            if(a[i]==b[j])          //Checking whether the value at i'th index of array1 is found in array2 using linear search
            {
                isFound=true;       //If match is found, then the flag is set to 'true' to indicate the match is found.
                swapIndex=j;        //storing the index to swap it to the position left to the i'th index. to ensure no already found element is again used for find subset element
                break;              //breaking the loop for iterating the next element
            }
        }
        if(isFound)                 // If element is found in arr2 then swap it position to the left of index 'i' (visited elements)
        {
            temp=b[i];              
            b[i]=b[swapIndex];
            b[swapIndex]=temp;
        }
        else 
            return false;           //if any single element in arr1 is not found on arr2 then a1 is not a subset of a2
    }

    return true;                    //if the loop does not break partially , then it means all the elements in arr1 are in arr2 , "a1 is subset of a2"
}

void main()
{
    int a[]={1,1,1},b[]={1,2,3};
    if(isSubsetArray(a,sizeof(a)/sizeof(int),b,sizeof(b)/sizeof(int)))    //Passing both the arrays to check whether they are subset , if function returns true then a1 is subset of a2
        printf("a1 is Subset of a2");
    else 
        printf("a1 is not a subset of a2");;
}
