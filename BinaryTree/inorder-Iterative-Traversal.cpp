#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Perform Inorder Traversal of Binary Tree Nodes by Iterative Approach,
    The Program creates and connects Binary Tree nodes manually by dynamic memory allocation at runtime ,
    A Stack is used for storing the nodes for traversal, All left nodes are stored in the stack and 
    the deepest leftmost node is printed and popped from the stack , then it's right child is pointed as current node where it's left nodes are pushed into the stack and this pattern repeats until the stack gets empty

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

void inOrder_Iterative_Traversal(BinaryNode* root)      //function to perform inorder traversal of BinaryTree by iterative approach
{
    if(root == nullptr)                 //if empty BinaryTree
        return;

    BinaryNode* current = root;         
    stack<BinaryNode*> s;               //creating stack for storing the nodes for inorder traversal 
    
    while(current != nullptr || !s.empty())             //loop until the current node is null and stack is empty
    {
        while(current != nullptr)
        {
            s.push(current);                        //pushing all the left node from the root to the deepest left node into the stack
            current = current->leftNode;
        }
        cout<<s.top()->data<<" ";                   //printing the deepest left node data
        current = (s.top())->rightNode;             //changing the pointer to point to the right subtree of the current node (because inorder Left -> Root -> Right)
        delete s.top();                              //deallocating the current top node from the memory by delete operator
        s.pop();                                    //popping the top node of the stack
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

    inOrder_Iterative_Traversal(root);                      //performing inorder traversal Iteratively


    return 0;
}
