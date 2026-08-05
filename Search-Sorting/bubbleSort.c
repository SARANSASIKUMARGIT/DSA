#include<stdio.h>
#include<math.h>
#include<stdbool.h>

        /*    Saran SK     */

void bubbleSort(int a[],int n)
{
    int temp;
    bool isSwapped=false;                   //to indicate whether swapping happened                      
    for(int i=0;i<n;++i)                    //traverse the arrray from index 0 to n-1
    {
        isSwapped=false;
        for(int j=0;j<n-i-1;++j)            //the inner loop swaps the adjacent element if current element is greater than its next element
        {                                   //traversing from 0 to n-i-1 because after every i number of iteration the last i elements of the array has been sorted therefore no need to visit them
            if(a[j]>a[j+1])
            {
                temp=a[j];                  //swaping the adjacent elements
                a[j]=a[j+1];
                a[j+1]=temp;
                isSwapped=true;             //setting flag to true to indicate that swapping has been happened in the i'th iteration
            }
        }

        if(!isSwapped)
            break;              //break, if no swap happened in the i'th iteration, then the array is sorted, therefore no need to sort anymore 
    }
}

void main()
{
    int a[]={10,3,43,23,4,8,1,12};

    printf("Before Bubble Sort : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");

    bubbleSort(a,sizeof(a)/sizeof(int));

    printf("After Bubble Sort  : ");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
        printf("%d ",a[i]);
    printf("\n");


}
