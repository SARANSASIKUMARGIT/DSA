#include<stdio.h>
#include<stdlib.h>  
#include<string.h>

        /*    Saran SK     */

/*
    C program to lower case a string 
*/

/*

            /*    Saran SK    */
void capitalize(char* str)
{
    for(int i=0;i<strlen(str);++i)
    {
        if(str[i]>=65 && str[i]<=90)
            str[i]+=32;
    }
}            
            


int main()
{
    char str[30];
    printf("Enter the String with numbers : ");
    fgets(str,sizeof(str),stdin);    //input the string (including spaces)
    
    printf("Before Captitalize : %s \n",str);
    capitalize(&str);
    printf("After Captitalize : %s \n",str);
    
    
    return 0;
    

}

    
