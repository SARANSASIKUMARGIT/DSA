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
    ListNode* lastNodeofReorderList(deque<ListNode*> &q,ListNode* root)
    {   
        if(root->next==nullptr)
        {
            q.front()->next=root;
            q.pop_back();
            q.pop_front();
            return root;
        }
        q.push_back(root->next);
        ListNode* reOrderList=lastNodeofReorderList(q,root->next);
        if(q.empty())
            return reOrderList;
        if(q.size()==1)
        {
            reOrderList->next=root;
            q.pop_front();
            return root;
        }
        q.front()->next=root;
        reOrderList->next=q.front();
        q.pop_front();
        q.pop_back();
        return root;

    }
    void reorderList(ListNode* head) {
        if(head==nullptr)
            return;
        if(head->next==nullptr)
            return;
        deque<ListNode*> q;
        ListNode* top=head;
        q.push_back(head);
        ListNode* reOrderList=lastNodeofReorderList(q,head);
        if(reOrderList)
            reOrderList->next = nullptr;
    }
};
