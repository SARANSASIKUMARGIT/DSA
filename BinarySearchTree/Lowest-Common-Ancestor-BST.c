#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to calculate the Lowest Common Ancestor of Two Nodes .
    The Lowest Common Ancestor(LCA) is the deepest node in a tree that is the ancestor (top nodeof both the nodes),
    A Node can be an Ancestor to itself.
    In this program the LCA of two nodes is found by recursive approach
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

struct BSTNode* LowestCommonAncestor(struct BSTNode* root,int p,int q)                      //function to find the LCA
{
    if(root==NULL)                        //if node is null
        return NULL;
    if(p< root->data && q< root->data)    //if both the nodes are less than the current node , then it should be on the left subtree, therefore moving to leftSubtree by recursion
        return LowestCommonAncestor(root->left,p,q);
    if(p> root->data && q > root->data )    //if both the node are greater than the current node, then it should be on the right subtree, therefore moving to right Subtree by recursion
        return LowestCommonAncestor(root->right,p,q);
    return root;                    //Split point or one node is equal to the root
}



int main()
{ 
    int n,num,p,q;
    printf("Enter the number of nodes of BST 1: ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d : ",i);
        scanf("%d",&num);
        root=insertNode(root,num);    //Inserting the node into BST1 and returning the address 
    }

    printf("Enter the value of P Node : ");
    scanf("%d",&p);
    printf("Enter the value of Q Node : ");
    scanf("%d",&q);
    
    struct BSTNode* LCA = LowestCommonAncestor(root,p,q);                               //Calling Lowest Common Ancestor()
    printf("LCA of Node %d and %d is %d \n",p,q,((LCA==NULL)?(-1):(LCA->data)));        //Printing the result . if NULL , then it meaans No LCA is found (-1)

    return 0;
}
