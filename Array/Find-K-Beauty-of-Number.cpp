#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC2269. Find the K-Beauty of a Number
  PS :The k-beauty of an integer num is defined as the number of substrings of num when it is read as a string that meet the following conditions:
      1.It has a length of k.
      2.It is a divisor of num.
      Given integers num and k, return the k-beauty of num.
  Note:
        Leading zeros are allowed.
        0 is not a divisor of any value.
        A substring is a contiguous sequence of characters in a string.

  TIME COMPLEXITY  :  O(N) N = number of digits of the integer 
  SPACE COMPLEXITY :  O(1) only constant extra space

*/

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int tempNum = num, i=0, subStringCount=0, currentDivisor = 0;
        while(i<k && tempNum)
        {
            int lastDigit = tempNum % 10;
            tempNum/=10;
            currentDivisor += (lastDigit*pow(10,i));
            ++i;
        }
        if(i!=k)
            return 0;
        if(currentDivisor!=0 && num%currentDivisor==0)
            ++subStringCount;
        
        while(tempNum)
        {
            currentDivisor /= 10;
            int lastDigit = tempNum % 10;
            tempNum/=10;
            currentDivisor += (lastDigit*pow(10,k-1));
            if(currentDivisor != 0 && num%currentDivisor==0)
                ++subStringCount;
        }

        return subStringCount;
        
    }
};
