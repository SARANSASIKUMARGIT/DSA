#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK   */
/*
  C++ Program for LC155 : Min Stack (Vector Approach)
  PS : Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
      Implement the MinStack class:
      MinStack() initializes the stack object.
      void push(int value) pushes the element value onto the stack.
      void pop() removes the element on the top of the stack.
      int top() gets the top element of the stack.
      int getMin() retrieves the minimum element in the stack.
  You must implement a solution with O(1) time complexity for each function.

TIME COMPLEXITY  : O(1) only constant time for every operation on the stack
SPACE COMPLEXITY : O(N) where N = maximum number of nodes in the stack throughout the lifetime of the program
*/

class MinStack {
public:
    vector<pair<int,int>> stack;
    int minValue;
    int topNodeIndex;
    MinStack() {
        minValue=INT_MAX;
        topNodeIndex=-1;
    }
    
    void push(int value) {
        stack.push_back({value,minValue});
        ++topNodeIndex;
        if(value<minValue)
            minValue = value;
    }
    
    void pop() {
        minValue = stack[topNodeIndex].second;
        stack.pop_back();
        --topNodeIndex;
    }
    
    int top() {
        return stack[topNodeIndex].first;
    }
    
    int getMin() {
        return minValue;
    }
};
