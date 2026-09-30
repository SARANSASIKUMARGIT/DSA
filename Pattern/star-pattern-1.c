#include <stdio.h>

        /* Saran SK */
    /*Star Pattern Program 
        Takes an Integer N as an input. 
        if N is even : N = N+1
        else : N = N
    */

int main() {

    int n,directionFlag = 1,adjustmentIndex=1;
    printf("Enter a odd number : ");
    scanf("%d",&n);
    n = (n%2==0)?(n+1):n;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(i==(n/2)+1)
            {
                printf("* ");
                directionFlag = 0;
            }
            else if(i==1 || i==n || j==1 || j==n || j==(n/2)+1 ||  j==adjustmentIndex || j==(n+1)-adjustmentIndex)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
        if(i==(n/2)+1)
            adjustmentIndex--;
        else
        {
            if(directionFlag)
                    adjustmentIndex++;
            else
                adjustmentIndex--;
        }
    }
    
    
    
    
        
    
    return 0;
}
