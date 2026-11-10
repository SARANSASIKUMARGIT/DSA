#include<bits/stdc++.h>
using namespace std;


          /*  Saran SK  */
/*
C++ Program for LC227 : Basic Calculator II
  PS : Given a string s which represents an expression, evaluate this expression and return its value. 
      The integer division should truncate toward zero.
      You may assume that the given expression is always valid. All intermediate results will be in the range of [-2^31, 2^31 - 1].
      Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

  TIME COMPLEXITY  : O(N) for traversing all characters of the strings
  SPACE COMPLEXITY : O(K) where K = sum of maximum number of elements in both operator and operand stack at any index 'i' throughout the traversal of the string s
*/

class Solution {
public:
    int precedence(char opr)
    {
        switch(opr)
        {
            case '/':
            case '*':
                return 2;
            case '+':
            case '-':
                return 1;
            default:
                return 0;
        }
    }

    int arithmeticOperation(char opr,int op1,int op2)
    {
        switch(opr)
        {
            case '/':
                return op1/op2;
            case '*':
                return op1*op2;
            case '+':
                return op1+op2;
            case '-':
                return op1-op2;
            default:
                return 0;
        }
    }
    int calculate(string s) {
        stack<int> operandStack;
        stack<char> operatorStack;
        int i=0;
        while(i<s.length())
        {
            while(i<s.length() && s[i]==' ')
                ++i;
            if(i>=s.length())
                break;
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            {
                char opr=s[i];
                if(operatorStack.empty())
                    operatorStack.push(s[i]);
                else
                {
                    while(!operatorStack.empty() && precedence(opr)<=precedence(operatorStack.top()))
                    {
                        char topOperator=operatorStack.top();
                        operatorStack.pop();
                        int op2 = operandStack.top();
                        operandStack.pop();
                        int op1 = operandStack.top();
                        operandStack.pop();
                        int result=arithmeticOperation(topOperator,op1,op2);
                        operandStack.push(result);
                    }
                    operatorStack.push(opr);
                }
                ++i;
            }
            else
            {
                int operand=0;
                while(i<s.length() && (s[i]>=48 && s[i]<=57))
                {
                    int digit = s[i]-48;
                    operand = (operand*10) + digit;
                    ++i;
                }
                operandStack.push(operand);
            }
        }
        while(!operatorStack.empty())
        {
            char opr = operatorStack.top();
            operatorStack.pop();
            int op2=operandStack.top();
            operandStack.pop();
            int op1=operandStack.top();
            operandStack.pop();
            int result = arithmeticOperation(opr,op1,op2);
            operandStack.push(result);
        }

        return operandStack.top();
    }
};
