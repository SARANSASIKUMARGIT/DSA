#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C program to calculate maximum path sum in a BST, 
    The Maximum path sum in a tree is the path of tree in which sum of values of all nodes are maximum , "NO SIMULTANEOUS PATH SELECTION"
    NOTE : Only one path can be selected , no multiple path for a single node can be selected for maximum sum, Select only the largest possible path ,
    THIS PROGRAM PERFORMS FINDING OF LCA ASSUMING THAT BOTH NODES P & Q ARE EXISTING IN THE NODE
*/

struct BSTNode *root=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initialy NULL)

struct BSTNode               //Defining the structure of node in the binary search Tree
{
    int data;                   //Variable for storing value of the node
    struct BSTNode *left;       //Pointer of type node that stores the memory address of its left child
    struct BSTNode *right;      //Pointer of type node that stores the memory address of its right child
};

struct BSTNode* createNode(int data)        //Function to create a new node at runtime in heap memory
{
    struct BSTNode* newNode=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

struct BSTNode* insertNode(struct BSTNode* root,int data)      //Function that inserts node to the Binary Search Tree
{
    if(root==NULL)
        return createNode(data);      //If the current node is NULL , create a node and link to its parent
    if(data == root->data)
        return root;                  //restrict duplicate nodes
    if(data < root->data)
        root->left=insertNode(root->left,data);    //if the value of data is less than the value of current root, then push it to it's left subtree
    else
        root->right=insertNode(root->right,data);  //if the value of data is greater than the value of current root , then push it to it's right subtree
    
    return root;       //Returns the current address to the caller which is the address of the calling itself (to ensure the structure of the BS Tree is Preserved)
}

int max(int a, int b)                       //function that returns the maximimum number of two numbers
{
    return (a>b)?a:b;
}

int maximumPathSumofBST(struct BSTNode* root,int* maximumSum)               //Function to calculate the maximum path sum of BST
{
    if(root==NULL)                 //if root is null , then value of that root is 0
        return 0;
    int leftTreeMaximumSumPath = maximumPathSumofBST(root->left,maximumSum);        //calculate the maximum Path sum of Left Subtree
    int rightTreeMaximumSumPath = maximumPathSumofBST(root->right,maximumSum);      //calculate the minimum Path sum of Right Subtree
    //stores the maximum value of (current Maximum sum value, current node value, current node value+left Subtree value , current node value + right Subtree value , current node value + leftSubtree value + rightSubtree value)
    *maximumSum = max(*maximumSum , max(root->data , max(root->data+leftTreeMaximumSumPath, max(root->data+rightTreeMaximumSumPath,root->data + leftTreeMaximumSumPath + rightTreeMaximumSumPath))));
    int singleLargestPath = max(root->data,max(root->data + leftTreeMaximumSumPath , root->data + rightTreeMaximumSumPath));
    return singleLargestPath;                                                      //returns only the maximum path to its parent (not it's both child because we need to select only one path of maximum sum)
}



int main()
{ 
    int n,num;
    printf("Enter the number of nodes of BST 1: ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d : ",i);
        scanf("%d",&num);
        root=insertNode(root,num);    //Inserting the node into BST1 and returning the address 
    }

    int maximumPathSum = INT_MIN;
    maximumPathSumofBST(root,&maximumPathSum);

    printf("Maximum Path Sum of the BST  :  %d \n",maximumPathSum);


    return 0;
}
