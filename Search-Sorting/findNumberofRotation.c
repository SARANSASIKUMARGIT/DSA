#include<stdio.h>

        /*    Saran SK     */

/*
    C Program to find rotation count of the sorted array using binary Search
    The index of the smallest element in the array is the number of times a sorted array is sorted, 
    thus by finding the index of the smallest element in the rotated array , the number of rotation is found.
    
    Time Complexity  : O(log N) as in every iteration the size of the searching range reduces by half ,
    Space Complexity : O(1)     only small constant extra space used
*/

int findNumberofRotation(int a[],int n)
{
    int start=0,end=n-1,mid,nextIndex,prevIndex;       //declaring prerequiste variables for storing indices             
    while(start<=end)                                  //while in valid range start<=end
    {
        if(a[start]<=a[end])                            // if element at index start is less than end , it means it is the smallest element
            return start;
        mid= start + (end-start)/2;                     //calculate middle index by preventing overflow 
        prevIndex=(mid+n-1)%n;                          //calculating previous and next index of the middle element by wraping them within the boundary of array using %n modulus operation
        nextIndex=(mid+1)%n;
        if(a[mid]<=a[prevIndex] && a[mid]<=a[nextIndex])    //the smallest element in the array always lesser than both it's neighbour, if true return middle index
            return mid;
        else if(a[mid]>a[end])                          //if middle element is greater than the end element , it means smallest value is on the right half
            start=mid+1;
        else
            end=mid-1;                                  //if middle element is lesser than end element , it means the smallest value is on the left half of the array
    }
    return -1;                              // in case of empty array or any exception , return -1
}

void main()
{
    int a[]={16,3,5,7,11,15};
    printf("%d",findNumberofRotation(a,sizeof(a)/sizeof(int)));    


}
