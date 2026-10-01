#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<stdbool.h>

bool isContainsDuplicate(int *nums, int numSize)
{
    for(int i=0;i<numSize;++i)
    {
        for(int j=i+1;j<numSize;++j)
        {
            if(nums[i]==nums[j])
                return true;
        }
    }
    return false;
}

int main() {

    int *arr=NULL,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr==NULL)
    {
        printf("Array Dynamic Memory Allocation Failed. Try again Later \n");;
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter Element %d : ",i);
        scanf("%d",arr+i);
    }
    
    if(isContainsDuplicate(arr,n))
        printf("Contains Duplicate \n");
    else
        printf("Contains No Duplicate \n");
    
        
    
    return 0;
}
