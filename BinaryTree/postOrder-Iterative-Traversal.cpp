#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Perform postOrder Traversal of Binary Tree Nodes by Iterative Approach,
    The Program creates and connects Binary Tree nodes manually by dynamic memory allocation at runtime ,
    Two Stack is used for storing the nodes of the Binary Tree with respect to postOrder Traversal and 
    Initially add the root node to the stack1 ,
    while the stack1 is not empty , push the top node to the stack2 and store the reference of the top node into another pointer ,
    push the left and right child of the previous top node of the stack1 into the stack1 respectively,
    repeat this until the stack1 gets empty

    Finally, Print all the nodes in the stack2 until it's get empty
    
    postOrder Traversal : Left -> Right -> Root

    TIME COMPLEXITY  : O(N)  Linear Time Complexity for traversing 2*N number of nodes ,
    SPACE COMPLEXITY : O(N) 
*/

struct BinaryNode                 //defining the structure of BinaryNode using struct 
{
    int data;                    //members of BinaryNode structure
    BinaryNode* leftNode;
    BinaryNode* rightNode;

    BinaryNode(int value) : data(value) , leftNode(nullptr) , rightNode(nullptr) {};            //constructor method to initialize members of the object
};

void postOrder_Iterative_Traversal(BinaryNode* root)      //function to perform postOrder traversal of BinaryTree by iterative approachl and deleting nodes at each traversal 
{
    if(root == nullptr)             //if tree is empty/null
        return;

    stack<BinaryNode*> s1,s2;      //declaring two stacks 
    s1.push(root);                 //push the root node to the stack1 initially
    
    while(!s1.empty())             //loop until the stack1 becomes empty
    {
        BinaryNode* current = s1.top();         //store the reference of the top node of the stack1
        s2.push(current);                       //push the top node of the stack1 to stack2 and pop it from the stack1
        s1.pop();                               

        if(current->leftNode)                   //push the left child node of the previous top node of the tree into the stack1
            s1.push(current->leftNode);
        if(current->rightNode)                  //push the right child node of the previous top node of the tree into the stack1
            s1.push(current->rightNode);
    }

    while(!s2.empty())                      //printing the nodes stored in the stack2 for postOrder traversal of nodes
    {
        cout<<s2.top()->data <<" ";         //printing the top node of the stack2 and deallocates the memory of the top node of the stack
        delete s2.top();
        s2.pop();                           //pop the top node of the stack2
    }
    cout<<endl;
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

    postOrder_Iterative_Traversal(root);                      //performing postOrder traversal Iteratively


    return 0;
}
