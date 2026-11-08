#include<bits/stdc++.h>
using namespace std;

        /*  Saran SK   */
/*
  C++ Program for LC155 : Min Stack (Dynamic Memory Allocation of Nodes of the stack)
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

struct stackNode
{
    int currentData;
    int minValue;
    struct stackNode* next;
};

class MinStack {
public:
    int minValue;
    struct stackNode* topNode;
    MinStack() {
        minValue=INT_MAX;
        topNode=nullptr;
    }
    
    void push(int value) {
        struct stackNode* newNode= new stackNode();
        newNode->currentData=value;
        newNode->minValue=minValue;
        newNode->next=topNode;
        topNode=newNode;
        if(value<minValue)
            minValue = value;
    }
    
    void pop() {
        minValue = topNode->minValue;
        struct stackNode* tempNode=topNode;
        topNode=topNode->next;
        delete tempNode;
    }
    
    int top() {
        return topNode->currentData;
    }
    
    int getMin() {
        return minValue;
    }
};
