#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to count the sum of values of all even nodes in a linked list.

    TIME COMPLEXITY  : O(N/2) for traversing only the even nodes of the linked list
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

int sumofEven_ListNodes(struct LinkedListNode* head)            //function to count the sum of values of even nodes of the linked list
{
    if(head == nullptr || head->next == nullptr)        //if list is empty or the second node (first even node) does not exist
        return 0;
    int sum = 0;
    head = head->next;          //pointing the reference to the second node (first even node) of the linked list
    while(head) 
    {
        sum += head->data;      //adding the value of the even node
        if(head->next == nullptr || (head->next)->next == nullptr)  //if current node is the last node or next even node does not exist
            return sum;
        head = (head->next)->next;      //pointing the reference to the next even element n+2 node
    }
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
    int n,num,target;
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

    cout<<"Linked List : \n";
    printLinkedList(headNode);   
    
    cout<<"\nSum of All Even Nodes of Linked List : "<<sumofEven_ListNodes(headNode)<<endl;          

    deleteLinkedList(headNode);
    headNode = nullptr;

    return 0;
}
