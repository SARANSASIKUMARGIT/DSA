#include<stdio.h>

    /*    Saran SK    */

/*    
    Sort Elements of an Array by Frequency   BRUTE FORCE APPROACH
    Problem Statement: Given an array of integers, having some duplicate elements, sort the array by frequency .

    Input: N = 8, array[] = {1,2,3,2,4,3,1,2}
    Output: 2 2 2 1 1 3 3 4 
    Explanation: Since  2 is present 3 times in an array , so print it 3 times ,then print ‘1’ 2 times and then ‘3’ 2 times and 4 has least frequency, it will be printed at last.

    Time Complexity  : O(N^2) as we use nested loop to count the frequency, which is in worst case (all unique elements) results in O(N^2) ,
    Space Complexity : O(N)   as we use linear amount of extra memory space for frequency and new Array sorted by frequency
    */

void orderByFrequency(int* a,int n)             
{
    int frequencyArray[n];                      //Array to store the frequency of the elements correspondingly
    int uniqueElements=0;                       //Variable to store the count of only unique elements neglecting the duplicate count
    for(int i=0;i<n;++i)
        frequencyArray[i]=-1;                   //Initiating the value of frequencyArray as -1 cause initially no elements are visited.
    for(int i=0;i<n;++i)
    {
        if(frequencyArray[i] == -1)             // if an element is not visited yet
        {
            frequencyArray[i]=1;                //set the frequency of that element to 1 initially and increment the uniqueElements as it is the first time the element is found.
            uniqueElements++;
            for(int j=i+1;j<n;++j)              
            {
                if(a[i]==a[j])                  //Checking for duplicate if found increment the frequency +1 in frequencyArray at index 'i'
                {
                    frequencyArray[j]=0;        //The duplicate element's index value is marked as 0 representing it is visited and no future iteration need to care about it
                    frequencyArray[i]++;        
                }
            }
        }
    }    
    int orderedArray[n];
    int newSize=0;
    while(uniqueElements--)                 //iterating while all the unique number of elements with their frequency is found.
    {
        int maxIndex=0;
        for(int i=0;i<n;++i)
        {                                                   
            if(frequencyArray[i]>frequencyArray[maxIndex])      //Finding the maximum value of frequency
                maxIndex=i;
            else if(frequencyArray[i]==frequencyArray[maxIndex])   //if both frequency are same. The element's index with smaller value is selected
                if(a[i]<a[maxIndex])
                    maxIndex=i;  
        }
        for(int i=0;i<frequencyArray[maxIndex];++i)             //Inserting the maximum frequency element in the new Array for it's frequency time
            orderedArray[newSize++]=a[maxIndex];
        frequencyArray[maxIndex]=0;                             //Setting the value of maxIndex=0 cause in the further iteration the next higher frequency should be selected.
        
    }
    
    for(int i=0;i<n;++i)                                //Printing the final orderedArray by their frequency
        printf("%d ", orderedArray[i]);
        
}

void main()
{
    int a[]={1,2,3,2,4,3,1,2};
    
    orderByFrequency(a,sizeof(a)/sizeof(int));  //Passing the array to be sorted with its length
    
}
