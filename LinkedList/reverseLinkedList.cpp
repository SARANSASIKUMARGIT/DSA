#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to dynamically create nodes and construct Singly Linked List and
    Reverse the Singly Linked List.

    TIME COMPLEXITY  : O(N) for traversing all the nodes of the linked list
    SPACE COMPLEXTIY : O(1) only constant extra space
*/

struct LinkedListNode                       //defining structure of a Linked List Node
{
    int data;                               //data member to store an integer value (data)
    struct LinkedListNode* next;            //pointer to the next node of the linked list (next pointer)
};

struct LinkedListNode* createLinkedListNode(int data=0)             //function to create Linked list node at runtime dynamically and returns the created Node
{
    LinkedListNode* newNode = new LinkedListNode;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

LinkedListNode* reverseLinkedList(struct LinkedListNode* headNode)
{
    LinkedListNode* prevNode = nullptr;
    LinkedListNode* nextNode = headNode;
    LinkedListNode* currentNode = headNode;
    while(nextNode)
    {
        currentNode = nextNode;
        nextNode = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
    }

    return currentNode;
}

struct LinkedListNode* appendNode(LinkedListNode* headNode,int data)            //function to append the new node at the end of the linked list
{
    if(headNode==nullptr)           //if linked list is empty(NULL) , create new node and return it as headNode
        return createLinkedListNode(data);

    LinkedListNode* tempNode = headNode;
    while(tempNode->next != nullptr)                //traverse until the last node
        tempNode= tempNode->next;
    tempNode->next = createLinkedListNode(data);        //create new node of value 'data' and points it to the next node of the current last node of the linked lists

    return headNode;                    //returning the headNode
}

void printLinkedList(struct LinkedListNode* headNode)
{
    while(headNode != nullptr)                  //traversing and printing the value of current node
    {
        cout<<headNode->data << " -> ";
        headNode = headNode->next;
    }
    cout<<endl;
}

void deleteLinkedList(LinkedListNode* headNode)
{
    LinkedListNode* currentNode = headNode;
    while(headNode)
    {
        currentNode = headNode;
        headNode = headNode->next;
        delete currentNode;
    }

}

int main()
{
    int n,num;
    struct LinkedListNode* headNode=nullptr;
    cout<<"Enter the number of nodes to add : ";
    cin>>n;
    //appending nodes to the linked list
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Node "<<i<<" value : ";
        cin>>num;
        headNode=appendNode(headNode,num);
    }

    cout<<"Linked List Before Reversing : ";
    printLinkedList(headNode);   
    
    headNode = reverseLinkedList(headNode);                 //calling function to reverse the linked list that returns the reverse the linked list and returns the last node as the head node
    cout<<"\nLinked List After Reversing : ";
    printLinkedList(headNode);          

    deleteLinkedList(headNode);                  //delete all nodes of the linked list
    headNode = nullptr;              

    return 0;
}
