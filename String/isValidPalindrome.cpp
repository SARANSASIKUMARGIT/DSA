#include<bits/stdc++.h>

            /* Saran SK */
/*
LC127 : 
  PS : A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
  Given a string s, return true if it is a palindrome, or false otherwise.

  TIME COMPLEXITY  : O(N) times grow in linear relationship with the number of alphanumeric characters in the string
  SPACE COMPLEXITY : O(1) only constant extra space
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int ptr=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]>=65 && s[i]<=90)
            {
                s[i]+=32;
                s[ptr++]=s[i];
            }
            else if((s[i]>=97 && s[i]<=122) || (s[i]>=48 && s[i]<=57))
                s[ptr++] = s[i];
        }
        int start=0,end=ptr-1;
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
};
