#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<stdarg.h>

                    /*   Saran SK    */

/*
        C Program to add only integer arguments in a list of Variable Length Arguments using va_list type , va_start(),va_args(),va_end() method
        and print all other arguments to output stream.

        TIME COMPLEXITY  : O(N) for traversing the N characters of the first argument (string),
        SPACE COMPLEXITY : O(1) only constant extra space
*/

int sumofAllIntegerArguments_inListofVariable_Length_Arguments(char* formatString, ...)
{
    // ... denotes the list of arguments of variable length/count 
    int sum = 0,val;
    va_list variableArguments;              //variable of type 'va_list' to hold the arguments
    va_start(variableArguments, formatString);      //initializing the 'variableArguments' to point the arguments after the argument 'formatString'
    char* tempStringPtr = NULL,*string=NULL;
    for(tempStringPtr = formatString; *tempStringPtr != 0; ++tempStringPtr)             //traversing the string until the end (\0) null terminator
    {
        if(*tempStringPtr != '%')
        {
            putchar(*tempStringPtr);
            continue;
        }
        switch(*++tempStringPtr)
        {
            case 'd':
                //integer argument , then the value of the argument should be added to the argument
                val = va_arg(variableArguments, int);          //interpreting the argument as type 'int'
                sum += val;                                    //adding the value of the integer argument to sum
                break;
            case 'c':
                //if %c
                printf("%%c =%c",va_arg(variableArguments,int));
                break;
            case 's':
                //if %s , then the argument is an character array, string
                string= va_arg(variableArguments, char*);    //interpreting the argument as type 'char*'
                printf("%%s = %s",string);
                break;
            case 'f':
                //%f 
                printf("%%f = %f",va_arg(variableArguments,double));    //interpreting the argument as type 'float'
                break;
            default:
                putchar(*tempStringPtr);
        }
    }

    return sum;
}

int main()
{ 
    int sumOfIntegerArguments = sumofAllIntegerArguments_inListofVariable_Length_Arguments("%d %c %s %c",100,'S',"ARAN S",'K');
    printf("\n\n\tSum of Values of Integer Arguments : %d ",sumOfIntegerArguments);

    return 0;
}
