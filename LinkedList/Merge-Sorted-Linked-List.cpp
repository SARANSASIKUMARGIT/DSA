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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sortedList = nullptr,*head=nullptr;
        while(list1 && list2)
        {
            ListNode* currentNode=nullptr;
            if(list1->val < list2->val)
            {
                currentNode=list1;
                list1=list1->next;
            }
            else
            {
                currentNode=list2;
                list2=list2->next;
            }
            if(sortedList == nullptr)
            {
                sortedList=currentNode;
                head=currentNode;
            }
            else
            {
                sortedList->next= currentNode;
                sortedList = sortedList->next;
            }
        }
        if(list1)
        {
            if(sortedList == nullptr)
            {
                sortedList = list1;
                head=list1;
            }
            else
            {
                sortedList->next = list1;
            }
        }
        if(list2)
        {
            if(sortedList == nullptr)
            {
                sortedList = list2;
                head=list2;
            }
            else
            {
                sortedList->next = list2;
            }
        }
        
        return head;
    }
};
