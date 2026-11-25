#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program for LC2. Add Two Numbers 
    PS : You are given two non-empty linked lists representing two non-negative integers. 
         The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
         You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    TIME COMPLEXITY  : O(N) for traversing all the nodes of both the linked list
    SPACE COMPLEXTIY : O(N) dynamically create N number of Nodes for storing the nodes of the result linked list
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int borrow=0;
    ListNode* resultHead=nullptr,*resultList=nullptr;
    while(l1 && l2)
    {
        ListNode* currentNode=nullptr;
        int num1= l1->val,num2= l2->val;
        int sum = borrow+num1+num2;
        if(sum>9)
        {
            borrow=1;
            currentNode = new ListNode(sum%10);
        }
        else
        {
            borrow=0;
            currentNode = new ListNode(sum);
        }
        if(resultHead==nullptr)
        {
            resultList=currentNode;
            resultHead=currentNode;
        }
        else
        {
            resultList->next=currentNode;
            resultList= resultList->next;
        }
        l1=l1->next;
        l2=l2->next;
    }
    while(l1)
    {
        ListNode* currentNode=nullptr;
        int sum = borrow+ (l1->val);
        if(sum>9)
        {
            borrow=1;
            currentNode = new ListNode(sum%10);
        }
        else
        {
            borrow=0;
            currentNode = new ListNode(sum);
        }
        if(resultHead==nullptr)
        {
            resultList=currentNode;
            resultHead=currentNode;
        }
        else
        {
            resultList->next=currentNode;
            resultList= resultList->next;
        }
        l1=l1->next;
    }
    while(l2)
    {
        ListNode* currentNode=nullptr;
        int sum = borrow+ (l2->val);
        if(sum>9)
        {
            borrow=1;
            currentNode = new ListNode(sum%10);
        }
        else
        {
            borrow=0;
            currentNode = new ListNode(sum);
        }
        if(resultHead==nullptr)
        {
            resultList=currentNode;
            resultHead=currentNode;
        }
        else
        {
            resultList->next=currentNode;
            resultList= resultList->next;
        }
        l2=l2->next;
    }
    if(borrow)
    {
        ListNode* newNode= new ListNode(1);
        resultList->next = newNode;
        resultList = resultList->next;
    }

    return resultHead;
    }
};
