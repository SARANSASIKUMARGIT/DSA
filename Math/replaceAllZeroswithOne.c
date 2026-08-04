#include<stdio.h>
#include<math.h>

        /*    Saran SK     */

/*
        C Program to replace all 0's in a given integer with 1 ,
        To replace 0's in an integer with 1, add the integer with sum of all digit place value of digits whose value is 0
        eg ; 1001 => 0 is on the ten's place and hundred's place , therefore adding 10+100 = 110 ,
        thus adding 1001 with   110 => 1001+110 = 1111     *all 0 digits all replaced with 1*

        Time Complexity  : O(D)  where D is the number of digits of the integer ,
        Space Complexity : O(1)  only constant extra space .
*/


long int replaceZeroswithOne(long int n)
{
    int additionValue=0;                            //value to be added with n at last to convert the number with 0's replaced by 1's
    long int duplicateValue=n,digitPlaceValue=1;
    while(duplicateValue)                           //while duplicateValue>0
    {
        if(duplicateValue%10 == 0)                  //if the current digit is 0, then add the digit place value to the addition variable
            additionValue += digitPlaceValue;
        digitPlaceValue*=10;                        //mulitply digitPlaceValue with 10 for each iteration , to maintain the correct digit place value
        duplicateValue/=10;                         //removing the last digit of the number by dividing by 10
    }
    return (n+additionValue);                       //adding the n with additionValue to get the number with all 0's replaced with 1's
}

void main()
{
    long int n;
    printf("Enter the integer : ");
    scanf("%ld",&n);                                                //Inputing the integer
    printf("Number after replacing 0's with 1's  : %ld \n",replaceZeroswithOne(n));         //Displaying the result                 


}
