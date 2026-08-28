#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to dynamically create, append, delete node in a Singly Linked List.
    The nodes are created using new operator in C++ , where they are deallocated using delete operator.
    After every create or append or deletion of nodes the head of the Linked list is returned by the function.
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

struct LinkedListNode* deleteLinkedListNode(LinkedListNode* headNode, int deleteNode)           //function to delete the node of given value in the linked list , no changes if node not found
{
    if(headNode==nullptr)                   //if linked list is empty (NULL)
        return nullptr;
    LinkedListNode* tempNode = headNode;        //copying the reference of headNode of linkedList for traversal , so that the original linked list gets returned after deletion of the node
    if(tempNode->data == deleteNode)
    {
        //if the head of the node is the node to be deleted
        LinkedListNode* tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;

        return headNode;
    }
    while(tempNode->next != nullptr && (tempNode->next)->data != deleteNode)        //move to the next node until the next node is the node to be deleted
        tempNode= tempNode->next;
    if(tempNode->next != nullptr)                           //if the next node of the current node is not NULL , then it means the current node is the node to be deleted
    {
        LinkedListNode* deletionNode = tempNode->next;      //storing the reference of the node to be deleted
        tempNode->next = (tempNode->next)->next;            //linking the current node to the next node of the next node(deletion node)
        delete deletionNode;                                // deleting the node
    }

    return headNode;               //returning the reference of the head node
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

    cout<<"Linked List Traversal after Node Creation : ";
    printLinkedList(headNode);          

    cout<<"Enter the node to delete : ";
    cin>>num;

    headNode = deleteLinkedListNode(headNode,num);          //deleting the node of value 'num' in the linked list

    cout<<"Linked List Traversal after Node Deletion : ";
    printLinkedList(headNode);

    while(headNode)                                         //deallocating all nodes from the memory before exit
    {
        LinkedListNode* tempNode = headNode;
        headNode = headNode->next;
        delete tempNode;
    }

    return 0;
}
