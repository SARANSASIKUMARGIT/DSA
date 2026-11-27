#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program for LC143. Reorder List
    PS : You are given the head of a singly linked-list. The list can be represented as:
          L0 → L1 → … → Ln - 1 → Ln
         Reorder the list to be on the following form:
          L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
         You may not modify the values in the list's nodes. Only nodes themselves may be changed.

    TIME COMPLEXITY  : O(N+N/2) 
    SPACE COMPLEXTIY : O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int findMiddle(ListNode* root,ListNode** middleNode,int currentNumber)
    {   
        if(root==nullptr)
            return 0;
        if(root->next==nullptr)
            return (currentNumber/2)+1;
        int middleNumber = findMiddle(root->next,middleNode,currentNumber+1);
        if(middleNumber==-1)
            return -1;
        if(middleNumber == currentNumber)
        {
            *middleNode = root;
            return -1;
        }
        return middleNumber;
    }
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        if(head->next==nullptr)
            return;
        ListNode* middleNode=nullptr;
        int middleNode = findMiddle(root,&middleNode,1);
        ListNode* startNode1=root,*startNode2=middleNode;
        ListNode* reOrderList=nullptr;
        while(startNode2 && startNode1!=middleNode)
        {
            ListNode* firstNode = startNode1;
            ListNode* secondNode = startNode2;
            startNode1 = startNode1->next;
            startNode2 = startNode2->next;
            if(reOrderList==nullptr)
            {
                reOrderList=firstNode;
                reOrderList->next=secondNode;
                reOrderList=reOrderList->next;
            }
            else
            {
                reOrderList->next=firstNode;
                firstNode->next=secondNode;
                reOrderList = secondNode;
            }
        }
        if(startNode2!=nullptr)
        {
            reOrderList->next=startNode2;
            reOrderList = reOrderList->next;
        }
        reOrderList->next=nullptr;
    }
};
