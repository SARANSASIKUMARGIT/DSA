#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/* Saran SK */

/* Program to find Symmetric pairs in an 2d array ,
    TIME COMPLEXITY : O(N^2) because of nested loop to check the matching pair in every iteration of i, 
    SPACE COMPLEXITY : O(1) no extra space.

    Input: (1,2),(2,1),(3,4),(4,5),(5,4)
    Output: (2,1) (5,4)
    NOTE: This Program is a BRUTE FORCE APPROACH, The OPTIMAL APPROACH can be achieved by Hash Maping.
*/

void findSymmetricPairinArray(int (*a)[2],int n)
{
    bool isMatchingPairFound=false;                 //Flag for verifying whether any matching pair is found or not
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(a[i][0]==a[j][1] && a[i][1]==a[j][0])        // checking for symmetric pair
            {
                printf("(%d,%d) ",a[i][0],a[i][1]);         //Printing the value of matched pair
                isMatchingPairFound=true;                   // set flag variable to true to indicate that a matching pair is found
                break;
            }
        }
    }
    if(!isMatchingPairFound)                            //if No Matching pair is found , for entire traversal
        printf("No Matching Pair Found ...");
}

void main()
{
    int a[][2]={{10,20},{30,40},{40,50}};
    findSymmetricPairinArray(a,sizeof(a)/(2*sizeof(int)));  //Passing two array with number of rows as argument

}
