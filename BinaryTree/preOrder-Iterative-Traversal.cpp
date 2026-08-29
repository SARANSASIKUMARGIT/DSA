#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Perform preOrder Traversal of Binary Tree Nodes by Iterative Approach,
    The Program creates and connects Binary Tree nodes manually by dynamic memory allocation at runtime ,
    A Stack is used for storing the nodes of the Binary Tree with respect to Preorder Traversal and 
    for every iteration print the top node of the stack and pop it from the stack by storing the top node using another pointer ,
    now insert the right node and left node of the previous popped top node whose reference is storing in another pointer ,
    Repeat the process until the stack becomes empty
    
    Preorder Traversal : Root -> Left -> Right

    TIME COMPLEXITY  : O(N)  for traversing N number of nodes ,
    SPACE COMPLEXITY : O(N) 
*/

struct BinaryNode                 //defining the structure of BinaryNode using struct 
{
    int data;                    //members of BinaryNode structure
    BinaryNode* leftNode;
    BinaryNode* rightNode;

    BinaryNode(int value) : data(value) , leftNode(nullptr) , rightNode(nullptr) {};            //constructor method to initialize members of the object
};

void preOrder_Iterative_Traversal(BinaryNode* root)      //function to perform preOrder traversal of BinaryTree by iterative approachl and deleting nodes at each traversal 
{
    if(root == nullptr)
        return;
    stack<BinaryNode*> s;                   //declaring stack for storing nodes of the binary tree
    s.push(root);                           //push the root into the stack 

    while(!s.empty())                       //loop until the stack becomes empty
    {
        BinaryNode* current = s.top();      //stores the reference of top node of the stack into another pointer 
        cout<<current->data << " ";         //print the data of the top node of the stack
        s.pop();                            // pop the top node of the stack

        if(current->rightNode)              //push the right child of the top node (recently popped) if not null
            s.push(current->rightNode);
        if(current->leftNode)               //push the left child of the top node (recently popped) if not null
            s.push(current->leftNode);

        delete current;                     //delete the node (previous top node) from the memory using delete operator
    }
}

int main()
{
    struct BinaryNode* root = new BinaryNode(10);               //manual constructing and connecting nodes of binary tree by dynamic memory allocation by new operator
    BinaryNode* leftTreeRoot1 = new BinaryNode(17);
    BinaryNode* rightTreeRoot1 = new BinaryNode(15);
    root->leftNode = leftTreeRoot1;
    root->rightNode = rightTreeRoot1;
    BinaryNode* leftTree_LeftChild = new BinaryNode(5);
    BinaryNode* leftTree_RightChild = new BinaryNode(8);
    leftTreeRoot1->leftNode = leftTree_LeftChild;
    leftTreeRoot1->rightNode = leftTree_RightChild;
    BinaryNode* rightTree_LeftChild = new BinaryNode(12);
    BinaryNode* rightTree_RightChild = new BinaryNode(6);
    rightTreeRoot1->leftNode = rightTree_LeftChild;
    rightTreeRoot1->rightNode = rightTree_RightChild;

    preOrder_Iterative_Traversal(root);                      //performing preOrder traversal Iteratively


    return 0;
}
