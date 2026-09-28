#include <stdio.h>
#include <string.h>

int main() {

    char str1[30],str2[30];
    int indexPtr = 0,isEqualString = 1;
    
    printf("Enter String 1 : ");
    fgets(str1, sizeof(str1),stdin);
    str1[strlen(str1)-1]=0;
    
    printf("Enter String 2 : ");
    fgets(str2, sizeof(str2),stdin);
    str2[strlen(str2)-1]=0;
    
    for(int i=0;i<strlen(str1);++i)
    {
        if(str1[i] != '#')
            str1[indexPtr++]= str1[i];
        else
        {
            if(indexPtr != 0)
                indexPtr--;
        }    
    }
    str1[indexPtr] = '\0';
    indexPtr = 0;
    
    for(int i=0;i<strlen(str2);++i)
    {
        if(str2[i] != '#')
            str2[indexPtr++]= str2[i];
        else
        {
            if(indexPtr != 0)
                indexPtr--;
        }    
    }
    str1[indexPtr] = '\0';
    
    if(strlen(str1) == strlen(str2))
    {
        for(int i=0;i<strlen(str1);++i)
        {
            if(str1[i] != str2[i])
            {
                isEqualString = 0;
                break;
            }
        }
    }
    else
        isEqualString = 0;
    
    if(isEqualString)
        printf("Both Strings are Equal");  
    else 
        printf("Both Strings are not equal");   
    
    
    
    
        
    
    return 0;
}
