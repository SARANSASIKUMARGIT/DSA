#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program for LC876. Middle of the Linked List (Slow and Fast Pointer Approach)
    PS : Given the head of a singly linked list, return the middle node of the linked list.
         If there are two middle nodes, return the second middle node.

    TIME COMPLEXITY  : O(N) for traversing all the nodes of the linked list
    SPACE COMPLEXTIY : O(1) only constant extra space
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        if(head->next==nullptr)
            return head;
        ListNode* middleNode=head;
        while(head && head->next)
        {
            if(head && head->next)
            {
                head=(head->next)->next;
                middleNode = middleNode->next;
            }
        }

        return middleNode;
    }
};
