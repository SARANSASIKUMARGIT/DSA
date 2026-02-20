#include<stdio.h>  
#include<string.h> 
#include<stdlib.h> 
 
//fibonacci series upto range n program 
//Saran Kumar S

void main()
{
    int a=-1,b=1,c,n;
    printf("Enter the range of fibonacci series : ");
    scanf("%d",&n);
    printf("%d %d ",a,b);
    c=a+b;
    while(c<=n)
    {
        printf("%d ",c);
        a=b;
        b=c;
        c=a+b;
    }
    
}
