#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Perform postOrder Traversal of Binary Tree Nodes by Iterative Approach using only 1 Stack , 
    The Program enters a loop and execute the following operations until the current pointer is not null or the stack is not empty,
    1.Push the current node to the stack and moves to the left node of the current and repeats this process until the current is not NULL,
    2.After the current = NULL ,which means there is no more nodes on the left of the current node , therefore we check whether the current node has a right child,
    3.If the current node has right child , then points the current pointer to the right child of the current node, therefore it iterative push all the left nodes of it's right child (including the right child itself),
    4.If the current node has no right child ,therefore print the current node and save the reference of current node in temp pointer and pops it from the stack,
        after popping , print the top node of the stack if the latest popped node is it's right child (temp == s.top()->rightNode) 
            if true then save the current top node of the stack in temp pointer, print the top node value and pop it from the stack and until the stack is not empty,
            else move to the next iteration where the value of current = NULL,
    The above operation gets performed until the condition (current != nullptr || !s.empty()) becomes false
    
    postOrder Traversal : Left -> Right -> Root

    TIME COMPLEXITY  : O(N)  Linear Time Complexity for traversing 2*N number of nodes ,
    SPACE COMPLEXITY : O(H)  H = Height of the Binary Tree
*/

struct BinaryNode                 //defining the structure of BinaryNode using struct 
{
    int data;                    //members of BinaryNode structure
    BinaryNode* leftNode;
    BinaryNode* rightNode;

    BinaryNode(int value) : data(value) , leftNode(nullptr) , rightNode(nullptr) {};            //constructor method to initialize members of the object
};

void postOrder_Iterative_Traversal(BinaryNode* root)
{
    if(root == nullptr)
        return;
    BinaryNode* current = root;
    stack<BinaryNode*> s;
    while(current != nullptr || !s.empty())
    {
        while(current)
        {
            s.push(current);
            current = current->leftNode;
        }
        BinaryNode* temp = s.top()->rightNode;
        if(temp == nullptr)
        {
            temp = s.top();
            s.pop();
            cout<<temp->data << " ";
            while(!s.empty() && temp == s.top()->rightNode)
            {
                temp = s.top();
                s.pop();
                cout<<temp->data << " ";
            }
        }
        else
            current = temp;
    }
}

void deleteTree(BinaryNode* root)
{
    if(root == nullptr)
        return;
    deleteTree(root->leftNode);
    deleteTree(root->rightNode);
    delete root;
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
    (rightTreeRoot1->rightNode)->leftNode = new BinaryNode(21);

    postOrder_Iterative_Traversal(root);                      //performing postOrder traversal Iteratively

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
