#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program for LC876. Middle of the Linked List 
    PS : Given the head of a singly linked list, return the middle node of the linked list.
         If there are two middle nodes, return the second middle node.

    TIME COMPLEXITY  : O(N+N/2) for traversing all the nodes of the linked list
    SPACE COMPLEXTIY : O(1) only constant extra space
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return head;
        ListNode* temp=head;
        int len=1;
        while(temp && temp->next)
        {
            len++;
            temp = temp->next;
        }
        int i=1,middle= (len/2)+1;
        while(head)
        {
            if(i==middle)
                return head;
            ++i;
            head=head->next;
        }
        return head;
    }
};
