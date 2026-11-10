#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK  */
/*
  C++ Program for LC921 : Minimum Add to Make Parentheses Valid
  PS : A parentheses string is valid if and only if:
      1.It is the empty string,
      2.It can be written as AB (A concatenated with B), where A and B are valid strings, or
      3.It can be written as (A), where A is a valid string.
      You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

      For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
      Return the minimum number of moves required to make s valid.

  TIME COMPLEXITY  : O(N) for traversing all characters of the strings
  SPACE COMPLEXITY : O(K) where K = Number of Consecutive open bracket '(' in the string s
*/

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<int> stack;
        int minMovesToMakeValid = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')                  
                stack.push(s[i]);
            else if(stack.empty())          //if no matching open bracket for close bracket
                ++minMovesToMakeValid;
            else
                stack.pop();                //if there exist an matching open bracket for close bracket
        }

        while(!stack.empty())              //if there exist any open brackets in the stack , pop them and add the count of minMoves
        {
            ++minMovesToMakeValid;
            stack.pop();
        }

        return minMovesToMakeValid;
    }
};

