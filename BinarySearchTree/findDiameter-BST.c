#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

/* Saran SK */

/*
    C Program to find the diameter of a Binary Search Tree,
    A Diameter of a tree is the longest path between any nodes in the tree.
    This Program finds the diameter of the tree by finding the maximum height leap node on both left and right subtree \
    on each recursive call and calculates the their maximum number of edges between them by adding (height of Left Subtree + height of Right Subtree + 1) \
    and returns maximum depth of the two subtrees on heightOfLeapNode() and 
    finally returns diameter at diameterOfBST() function

*/

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

struct BSTNode *root=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initialy NULL)

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

int max(int a,int b)
{
    return (a>b)?a:b;
}

int heightOfLeapNode(struct BSTNode* root,int* diameter)                //function to find the height of the subtree and returns length(height) of longest subtree by recursive approach
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int leftSubTreeHeight=heightOfLeapNode(root->left,diameter);
    int rightSubTreeHeight=heightOfLeapNode(root->right,diameter);
    *diameter=max(*diameter,(leftSubTreeHeight+rightSubTreeHeight+1));
    return (1+max(leftSubTreeHeight,rightSubTreeHeight));
}

int diameterOfBST(struct BSTNode* root,int* diameter)               //function similar to heightOfLeapNode but returns the diameter instead of maximum height of the subtree
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int leftSubTreeHeight=1+heightOfLeapNode(root->left,diameter);
    int rightSubTreeHeight=1+heightOfLeapNode(root->right,diameter);
    if( (leftSubTreeHeight+rightSubTreeHeight-1) > *diameter)
        *diameter=(leftSubTreeHeight+rightSubTreeHeight-1);
    return *diameter;
}


void main()
{ 
    int n,num;
    printf("Enter the number of nodes of BST : ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d : ",i);
        scanf("%d",&num);
        root=insertNode(root,num);    //Inserting the node into BST and returning the address 
    }

    int diameter=0;
    diameter=diameterOfBST(root,&diameter);                 //calling diameterOfBST() with root node reference and diameter variable reference
    printf("Diameter of the BST is : %d",diameter);

}
