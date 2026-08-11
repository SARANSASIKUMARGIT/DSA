#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* Saran SK */

/*
    C Program to find Whether Two Binary Search Trees (BST) are Identical ,
    Two Trees are Identical if both of them are exactly the same.
    This Program uses recursion technique to check whether the nodes of two nodes in each tree in each level is same , \
    if true it moves to their respective child node to check their equality , 
    else return false and end the function .
*/

struct BSTNode *root1=NULL,*root2=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initialy NULL)

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
    if(data < root->data)
        root->left=insertNode(root->left,data);    //if the value of data is less than the value of current root, then push it to it's left subtree
    else
        root->right=insertNode(root->right,data);  //if the value of data is greater than the value of current root , then push it to it's right subtree
    
    return root;       //Returns the current address to the caller which is the address of the calling itself (to ensure the structure of the BS Tree is Preserved)
}

bool isIdenticalTrees(struct BSTNode* root1, struct BSTNode* root2)         //function to check whether both current nodes of two different trees are equal ?
{
    if(root1==NULL && root2==NULL)                          //if both current nodes of two trees are NULL, then return true (identical)
        return true;
    if(root1==NULL || root2==NULL)                          //if any one of the nodes of the tree is not NULL and other node is NULL , then return false (non-identical)
        return false;
    if(root1->data==root2->data)                            //if both current nodes of two trees are identical , then checks for equality of their child nodes recursively
        return isIdenticalTrees(root1->left,root2->left) && isIdenticalTrees(root1->right,root2->right);
    return false;
}

void main()
{ 
    int n,num;

    //Tree 1
    printf("Enter the number of nodes of BST 1: ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d : ",i);
        scanf("%d",&num);
        root1=insertNode(root1,num);    //Inserting the node into BST1 and returning the address 
    }

    //Tree 2
    printf("Enter the number of nodes of BST 2: ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d : ",i);
        scanf("%d",&num);
        root2=insertNode(root2,num);    //Inserting the node into BST2 and returning the address 
    }

    if(isIdenticalTrees(root1,root2))               //printing the result
        printf("Tree 1 and Tree 2 are Identical \n");
    else
        printf("Tree 1 and Tree 2 are not Identical \n");

}
