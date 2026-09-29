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
    
    int totalStrlength = strlen(str1)+strlen(str2)+1;
    char *finalStr = (char*)malloc(totalStrlength);
    
    for(int i=0;i<strlen(str1);++i)
        finalStr[i]=str1[i];
    for(int j=strlen(str1);j<totalStrlength-1;++j)
        finalStr[j]= str2[j-strlen(str1)];
    finalStr[totalStrlength] = '\0';
    
    printf("Concatenated String : %s ",finalStr); 
    
    
    
        
    
    return 0;
}
