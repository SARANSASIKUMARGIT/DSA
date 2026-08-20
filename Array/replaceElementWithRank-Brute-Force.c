#include<stdio.h>
#include<stdlib.h>  
#include<limits.h>

        /*    Saran SK     */

/*
    C Program to Replace the elements of the array with its RANK,
    Rank of an element is the number of smaller element than it + 1 ,
    This Program is an BRUTE-FORCE approach to find the rank of element of the array by finding the number of elements less than it and 
    storing the rank in an Extra array 'rankArr' and
    An Extra Array 'resultArr' is used for storing the corresponding rank of the element.
    The Optimal Solution will take only less Space and Time compared to this Brute Force Approach,

    Time Complexity is O(N^2) due to nested loops to find the rank of each element and find the element with smallest to largest rank
    Space Complexity for this Program is O(2N) which is O(N),
*/

void replaceElementWithRank(int* arr, int* rankArr, int* resultArr, int n)
{
    //To Find the rank from Low to Max in corresponding order and storing the rank of element at corresponding respective index of the final 'resultArr'
    int rank=1,count=0;
    while(count<n)
    {
        int smallRankIndex = 0;
        for(int i=0;i<n;++i)
        {
            if(rankArr[i]<rankArr[smallRankIndex])
                smallRankIndex = i;
        }

        for(int i=smallRankIndex+1;i<n;++i)
        {
            if(rankArr[i]==rankArr[smallRankIndex])
            {
                resultArr[i]=rank;
                rankArr[i]=INT_MAX;
                count++;
            }
        }
        resultArr[smallRankIndex]=rank++;
        rankArr[smallRankIndex]=INT_MAX;
        count++;
    }
}

void calculateRank(int *arr,int *rankArr,int n)
{
    //Function to calculate the rank of each element of the array
    for(int i=0;i<n;++i)
    {
        rankArr[i]=0;
        for(int j=0;j<n;++j)
        {
            if(arr[j]<arr[i])
                rankArr[i]++;
        }
    }
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
    int n;
    int *arr=NULL, *rankArr=NULL, *resultArr=NULL;
    printf("Enter the number of array elements : ");
    scanf("%d",&n);
    
    if(n>0)             // if invalid value of n
    {
        arr=(int*)malloc(n*sizeof(int));
        rankArr=(int*)malloc(n*sizeof(int));
        resultArr=(int*)malloc(n*sizeof(int));
    }
    if(arr==NULL || rankArr==NULL || resultArr==NULL)               // if memory allocation failed for any dynamic array
    {
        printf("Memory Allocation Failed . Please Try Again \n");
        return 1;
    }
    for(int i=0;i<n;++i)                //initializing both the array with value -1
    {
        rankArr[i]=-1;
        resultArr[i]=-1;
    }

    inputArray(arr,n);
    printf("\nArray Before Replacing with Rank : ");
    for(int i=0;i<n;++i)
        printf("%d ",arr[i]);
    printf("\n");

    calculateRank(arr,rankArr,n);
    replaceElementWithRank(arr,rankArr,resultArr,n);                //calling for replacing Element with Rank

    printf("\nArray After Replacing with Rank : ");
    for(int i=0;i<n;++i)                                            //printing the final 'resultArr' (rank of each element)
        printf("%d ",resultArr[i]);
    printf("\n");

    free(arr);                                                      //deallocating the memory allocated for arrays
    free(rankArr);
    free(resultArr);

    


    return 0;

}



