#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to create , append , delete nodes dynamically at runtime and link them sequentially (Linked List)
*/

struct LinkedListNode 
{
    int data;
    struct LinkedListNode* next;
};

struct LinkedListNode* createLinkedListNode(int data=0)
{
    LinkedListNode* newNode = new LinkedListNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

struct LinkedListNode* deleteLinkedListNode(LinkedListNode* headNode, int deleteNode)
{
    if(headNode==nullptr)
        return nullptr;
    LinkedListNode* tempNode = headNode;
    if(tempNode->data == deleteNode)
    {
        headNode = tempNode->next;
        delete tempNode;
        return headNode;
    }
    while(tempNode->next != nullptr && (tempNode->next)->data != deleteNode)
        tempNode= tempNode->next;
    if(tempNode->next != nullptr)
    {
        tempNode->next = (tempNode->next)->next;
        delete tempNode;
    }
    return headNode;
}

struct LinkedListNode* appendNode(LinkedListNode* headNode,int data)
{
    if(headNode==nullptr)
    {
        LinkedListNode* newNode = createLinkedListNode(data);
        return newNode;
    }
    LinkedListNode* tempNode = headNode;
    while(tempNode->next != nullptr)
        tempNode= tempNode->next;
    tempNode->next = createLinkedListNode(data);

    return headNode;
}

void printLinkedList(struct LinkedListNode* headNode)
{
    while(headNode != nullptr)
    {
        cout<<headNode->data << " ";
        headNode = headNode->next;
    }
    cout<<endl;
}

int main()
{
    int n,num;
    struct LinkedListNode* headNode=nullptr;
    cout<<"Enter the number of nodes to add : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Node "<<i<<" value : ";
        cin>>num;
        headNode=appendNode(num);
    }

    cout<<"Linked List Traversal after Node Creation : ";
    printLinkedList(headNode);

    cou<<"Enter the node to delete : ";
    cin>>num;

    headNode = deleteLinkedListNode(headNode,num);

    cout<<"Linked List Traversal after Node Deletion : ";
    printLinkedList(headNode);

    return 0;
}
