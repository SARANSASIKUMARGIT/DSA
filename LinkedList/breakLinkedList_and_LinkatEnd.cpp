#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to break a singly linked list into two linked list at a specific node 
    and link the first linked list into the end of the second linked list.

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

struct LinkedListNode* breakLinkedList_AndLinkAtEnd(struct LinkedListNode* head,int key)  //function to break a singly linked list into two at a specific node 
{                                                                                          //and link the first linked list into the end of the second linked list
    struct LinkedListNode *current = head,*end= head,*prev=nullptr;
    struct LinkedListNode* newHead = nullptr;

    while(current)                          //traversing the nodes of the linked list until the end 
    {
        if(current->data == key)            //if current node is the target node
        {
            newHead = current;              //then the current node is the head of the linked list
            if(prev)
                prev->next = nullptr;       //breaking the linked list, by assigning the previous node's next reference to NULL
            while(current->next)            //traversing to the last node of the list
                current = current->next;
        }
        prev = current;                     //saving current node as previous and end node for every traversal
        end = current;
        current = current->next;            //moving to the next linked node
    }

    if(head == end || newHead == nullptr)       //if only single node or no target node is found, then return the default head node
        return head;
    end->next = head;                           //else assign the next reference of the end node to the head(head of first breaked linked list)
    return newHead;                         //return the reference of 'newHead'
    
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

    cout<<"Enter the value of node at which the Linked List is to be Breaked : ";
    cin>>target;

    cout<<"Linked List Before Breaking into two and append the first linked list into the end : \n";
    printLinkedList(headNode);   
    
    headNode = breakLinkedList_AndLinkAtEnd(headNode,target);
    cout<<"\nLinked List After Breaking into two and append the first linked list into the end : \n";
    printLinkedList(headNode);          

    deleteLinkedList(headNode);
    headNode = nullptr;

    return 0;
}
