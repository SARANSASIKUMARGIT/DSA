#include<stdio.h>
#include<string.h>

            /*    Saran SK    */

int sumOfNumbersinString(char *str)
{
    int sum=0, number = 0;
    for(int i=0; i<strlen(str); ++i)
    {
        while(i<strlen(str) &&(str[i]<'0' || str[i]>'9'))  //skipping all non-numeric character 
            ++i;
        if(i>=strlen(str))        //if string length exceeded 
            break;    
        number = 0;     //used to calculate the number
        while(i<strlen(str) &&(str[i] >= '0' && str[i] <= '9'))
        {
            number = (number*10) + (str[i] - '0');     //calculate the consecutive numeric characters as a number 
            ++i;     //incrementing the i to next character 
        }    
        sum+=number;    //adding the calulated number with the sum
    }
    return sum;           // returning the entire sum of all numbers 
}

int main()
{
    char str[30];
    printf("Enter the String with numbers : ");
    fgets(str,sizeof(str),stdin);    //input the string (including spaces)
    
    str[strlen(str)-1]=(str[strlen(str)-1]=='\n')?'\0':str[strlen(str)-1];    // if last character of string is \n (newline character) replace with \0 (null terminator)
    //passing string as parameter to calculate sum of all numbers 
    printf("\nSum of Numbers in Strings : %d\n",sumOfNumbersinString(str));
    
    return 0;
    

}
