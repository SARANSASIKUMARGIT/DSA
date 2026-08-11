#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

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

int calculateHeightAndDiameter(struct BSTNode* root,int* diameter)                      //calculate maximum height of both left and right subtrees of every node
{
    if(root==NULL)
        return 0;
    int leftLeafNodeHeight = calculateHeightAndDiameter(root->left,diameter);
    int rightLeafNodeHeight = calculateHeightAndDiameter(root->right,diameter);
    *diameter=max(*diameter, leftLeafNodeHeight+rightLeafNodeHeight+1);                 //checking whether the current path between the leftMost Depth Leaf node and RightMost Depth Leaf node is maximum than previous path

    return 1+(max(leftLeafNodeHeight,rightLeafNodeHeight));                             //returning the maximum height between the heights of left and right subtree of a node
}


int diameterOfBST(struct BSTNode* root,int* diameter)
{
    if(root==NULL)                  //if node is NULL , then diameter = 0
        return 0;
    calculateHeightAndDiameter(root,diameter);          //calls calculateHeightAndDiameter() method to calculate the diameter of the tree
    return *diameter;                                   //returns diameter by dereferencing the pointer
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
    diameter=diameterOfBST(root,&diameter);
    printf("Diameter of the Tree : %d ",diameter);

}
