#include<stdio.h>

        /*    Saran SK     */

/*
    Binary Search Program in C to find an element's first or last occurence in an sorted array with duplicate elements,
    Time Complexity  : O(log N) as in every iteration the size of the searching range reduces by half ,
    Space Complexity : O(1)     only small constant extra space used
*/
int binarySearch(int a[],int n,int key,int findFirstOccurence)
{
    int start=0,end=n-1,mid,result=-1;                //declaring starting,ending resutl and mid variable to store corresponding index
    while(start<=end)                       //while the start index is less than the end index (correct range)
    {
        mid=start + (end-start)/2;          //caluculating middle index , start+(end-start)/2 is used to prevent overflow if index values are larger
        if(a[mid]==key)                     //if key is found , check the 'findFirstOccurence' flag 
        {
            result=mid;                     //storing the middle index 
            if(findFirstOccurence)          //if true , move further to the left of the array for finding first occurence of key value
                end=mid-1;
            else
                start=mid+1;                //else , moving right of the array for finding the last occurence of the key value
        }
        else if(a[mid]>key)                      //if middle element is greater than the key , that means the key is in the left half of the array , end =mid-1
            end=mid-1;
        else
            start=mid+1;                    //if middle element is less than the key , it means the key is in the right half of the array, start=mid+1
    }
    return result;                          //if key is found the found index is returned , else -1 is returned
}

void main()
{
    int a[]={2,6,12,13,17,21,26,32},key,isFindFirstOccurence;
    printf("Enter the value to find : ");
    scanf("%d",&key);                                                   //Inputing the value to find from the user
    printf("To find first occurence enter 1 (or) to find last occurence enter 0 : ");
    scanf("%d",&isFindFirstOccurence);
    int res=binarySearch(a,sizeof(a)/sizeof(int),key,isFindFirstOccurence);
    if(res!=-1)                                                     // if key is found in the array
        printf("Key %d is found in index %d ",key,res);
    else
        printf("Key %d is not found ..",key);                       // if key not found in the array
}
