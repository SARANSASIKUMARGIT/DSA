#include<stdio.h>

        /*    Saran SK     */

void merge(int a[],int low,int mid,int high)
{
    int temp[(high-low)+1],i=0;                             //declaring temporary array of size (high-low+1) to store sorted order of elements
    int left=low,right=mid+1;                               
    while(left<=mid && right<=high)                         //appending the element of both sorted array until any one of the sorted array is completely appended into temporary array
    {
        if(a[left]<=a[right])                                //if current element of ( left array <= right array) then append left array element and increment left pointer by 1
            temp[i++]=a[left++];
        else
            temp[i++]=a[right++];                           //if current element of (right array < left array) then append right array element and increment the right pointer by 1
    }
    while(left<=mid)                                        //if any one part of the divided array is still need to be appended into temporary array, therefore appending it
        temp[i++]=a[left++];
    while(right<=high)
        temp[i++]=a[right++];
    //copying the sorted elements in temporary array to the original array from index low - high
    for(int j=0;j<i;++j)
        a[low+j]=temp[j];
}

void mergeSort(int a[],int low,int high)                    
{
    int mid= low + (high-low)/2;                    //calculating the middle index of the range low to high
    if(low<high)                                    //if low index <high , then valid range it means single element is only left which can't be divided further 
    {
        mergeSort(a,low,mid);                       //dividing the array from [low..mid] by recursive call
        mergeSort(a,mid+1,high);                    //dividing the array from [mid+1..high] by recursive call
        merge(a,low,mid,high);                      //after dividing the array into two parts until it can't be divided into further , merge them in sorted order in the original array
    }

}

void main()
{
    int a[]={10,3,43,23,4,8,1,12};

    printf("Before Merge Sort : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");

    mergeSort(a,0,(sizeof(a)/sizeof(int))-1);               //calling the mergeSort function with array,low index , high index

    printf("After Merge Sort : ");                          //Printing the sorted array after mergeSort
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");


}
