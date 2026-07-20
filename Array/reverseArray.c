#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

/* Saran SK */

void reverseArray(int *a,int n)
{
    int i=0,j=n-1,temp;
    while(i<j)
    {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        // a[i]+=a[j];         -> Risk of Arithmetic Overflow in case of large value of a[i] and a[j]
        // a[j]=a[i]-a[j];
        // a[i]=a[i]-a[j];
        ++i;--j;
    }

}



void main()
{
    int a[]={90,0,90,0,89,21,99,212};
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
    printf("%d  ",a[i]);
    printf("\n");
    reverseArray(a,sizeof(a)/sizeof(int));
    for(int i=0;i<sizeof(a)/sizeof(int);++i)
    printf("%d  ",a[i]);

    
}
