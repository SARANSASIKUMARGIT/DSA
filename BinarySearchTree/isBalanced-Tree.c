#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>

/* Saran SK */

/*
    C Program to Check whether a Tree is Balanced ?
    Balanced Tree : A Tree is balanced if the difference between the Height of Left subtree and Right subtree is <= 1 for every node on the tree ,
    if any node of the tree fails this condition , then the tree is not balanced.
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

int isBalancedTree(struct BSTNode* root)                                    //function to check whether the Tree is Balanced or not
{
    if(root==NULL)                                                          //if root is NULL         
        return 0;
    int leftSubTreeMaxHeight = isBalancedTree(root->left);                  //Calculate the height of left SubTree
    if(leftSubTreeMaxHeight == -1)                                          //if height of Left SubTree = -1 then it means the Left subtree is unbalanced, then the entire Tree is unbalanced.
        return -1;

    int rightSubTreeMaxHeight = isBalancedTree(root->right);                //calculate the height of Right Subtree
    if(rightSubTreeMaxHeight == -1)                                         //if height of Right SubTree = -1 then it means the Right subtree is unbalanced, then the entire Tree is unbalanced.
        return -1;

    if( abs(leftSubTreeMaxHeight-rightSubTreeMaxHeight) > 1)                //If difference between Height of Left and Right is >1 then the current node is unbalanced , which means the entire tree itself is unbalanced
        return -1;

    return 1+max(leftSubTreeMaxHeight, rightSubTreeMaxHeight);              //if difference is <= 1 , then return the maximum height between left and right subtree + 1(including the current parent node)
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
        root=insertNode(root,num);    //Inserting the node into BST1 and returning the address 
    }

    if(isBalancedTree(root) != -1)
        printf("The Tree is balanced \n");
    else
        printf("The Tree is not balanced \n");   

}
