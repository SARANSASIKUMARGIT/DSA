#include<bits/stdc++.h>
using namespace std;

          /*  Saran SK  */
/*
C++ Program for LC1021 : Remove Outermost Parentheses
PS : A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
    For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
    A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
    Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
    Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.
TIME COMPLEXITY  : O(N)
SPACE COMPLEXITY : O(K) where K = number of consecutive open brackets
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> stack;
        string result;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            {
                if(!stack.empty())
                    result+=s[i];
                stack.push(s[i]);
            }
                
            else
            {
                stack.pop();
                if(!stack.empty())
                {
                    result+=s[i];
                }
            }
        }
        return result;
    }
};
