#include<bits/stdc++.h>
using namespace std;

      /*  Saran SK  */
/*
C++ program for LC20 : Valid Parentheses 
  PS   : Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
        An input string is valid if:
        1.Open brackets must be closed by the same type of brackets.
        2.Open brackets must be closed in the correct order.
        3.Every close bracket has a corresponding open bracket of the same type.
  TIME COMPLEXITY  : O(N)
  SPACE COMPLEXITY : O(K) where K=number of consecutive open brackets
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
                stack.push(s[i]);
            else
            {
                char complimentChar = (s[i]==')')?('('):((s[i]=='}')?'{':'[');
                if(!stack.empty() && stack.top()==complimentChar)
                    stack.pop();
                else
                    return false;
            }
        }
        if(!stack.empty())
            return false;
        
        return true;
    }
};
