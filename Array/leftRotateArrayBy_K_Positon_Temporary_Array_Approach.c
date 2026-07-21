#include<stdio.h>
#include<stdlib.h>

/* Saran SK */

/* Program to Left Rotate an Array by K positon - TEMPORARY ARRAY METHOD */

void rotateArraybyK_Places(int *a,int n,int k)
{
    k=k%n;  //Because Number of rotation that is a mutliple of N will result in the same original array hence k mod n removes unneccesary number of rotations
    int temporaryArray[k];          //temporary array for storing first k elements
    for(int i=0;i<k;++i)            
        temporaryArray[i]=a[i];     //Storing first K elements in the temporary array
    for(int i=k;i<n;++i)
        a[i-k]=a[i];                //Moving elements from index i=k to N to the index i-k
    for(int i=n-k;i<n;++i)
        a[i]=temporaryArray[i-(n-k)];   //Assigning last K index elements of the array with the values in temporary array
    
}

void main()
{
    int a[]={9,3,6,1,10,7},k; 
    printf("Enter the value of k to rotate Left : ");
    scanf("%d",&k);                                    //Input K from User
    rotateArraybyK_Places(a,sizeof(a)/sizeof(int),k);      //Left Rotating the array by K places
    printf("\nAfter K Left Rotation : \n");
    for(int i=0;i<sizeof(a)/sizeof(int);++i)            //Print the Left Rotated Array
        printf("%d  ",a[i]);
    printf("\n");

}
