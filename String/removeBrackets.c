#include<stdio.h>
#include<string.h>

            /*    Saran SK    */

void removeBrackets(char *str)
{
    int pointer=0;            // initially pointer to index 0
    for(int i=0;i<strlen(str);++i)
    {
        //pause the pointer when str[i] is a bracket 
        if(str[i] != '(' && str[i] != ')' )    //if any character of str is not bracket , then str[pointer] is assigned the current str[i] and pointer is incremeted 
            str[pointer++] = str[i];
    }
    str[pointer] = '\0';    // assignment the last pointer index value to '\0' (null terminator) to end the string 
}

int main()
{
    char str[30];
    printf("Enter the Algebric Expression : ");
    fgets(str,sizeof(str),stdin);    //input the string (including spaces)
    
    str[strlen(str)-1]=(str[strlen(str)-1]=='\n')?'\0':str[strlen(str)-1];    // if last character of string is \n (newline character) replace with \0 (null terminator)
    //passing string as parameter to remove brackets 
    removeBrackets(str);        
    printf("\nString after Removing Brackets : %s\n",str);
    
    return 0;
    

}

