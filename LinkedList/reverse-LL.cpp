#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program for LC206. Reverse Linked List
    PS : Given the head of a singly linked list, reverse the list, and return the reversed list.

    TIME COMPLEXITY  : O(N) for traversing all the nodes of the linked list
    SPACE COMPLEXTIY : O(1) only constant extra space
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr,*next=head;
        while(next)
        {
            head=next;
            next = head->next;
            head->next=prev;
            prev=head;
        }

        return head;
    }
};
