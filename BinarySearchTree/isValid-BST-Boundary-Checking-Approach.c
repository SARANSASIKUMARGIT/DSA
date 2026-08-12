#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to check whether a Binary Search Tree (BST) is valid or not ?
    A BST is valid only if for each node all the nodes on it's left are less than it and
    all the nodes on it's right are greater than it. 
    Otherwise , it is not a Valid BST.

    This program validates the BST by boundary checking by verifing whether each node > minValue && node < maxValue ,
    the maximum value for left subtree is the value of the currentNode ,
    the minimum value for right subtree is the value of the currentNode,
    initially for the root node the minValue = INT_MIN and maxValue = INT_MAX ,
    if any the value of any node in the BST does not in this range (minValue < currentNode value < maxValue)
    then the tree is not a valid BST, 
    if it satisfies this range for every node then the tree is a valid BST
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

struct BSTNode* fetchNode(struct BSTNode* root,int value)               //Function to fetch a node with specific value to perform manual insertion into node so that the Tree can be tested for validity
{
    if(root==NULL)
        return NULL;
    if(value == root->data)
        return root;
    if(value < root->data)
        return fetchNode(root->left,value);
    if(value > root->data)
        return fetchNode(root->right,value);
}

bool isValidBST(struct BSTNode* root,int min,int max)                   //function to check whether a BST is valid or not?
{
    if(root==NULL)                              // if null node return True
        return true;
    if(root->data > min && root->data < max)       //if currentNode satisfies the boundary range (minValue < currentNode Value < maxValue ) then ,
        return isValidBST(root->left,min,root->data) && isValidBST(root->right,root->data,max);     // validate it's left and right subtree
    return false;                                           //not a balanced tree (out of boundary range)
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

    struct BSTNode* node = fetchNode(root,num);              //fetching the last node inserted into the BST to perform manual invalid node insertion 
    if(node!=NULL)
        node->right= createNode(node->data -1);             //to perform manual invalid insertion into BST to test the function isValidBST()

    if(isValidBST(root,INT_MIN,INT_MAX))                    //calling the isValidBST() to validate the BST by passing it's root
        printf("The Tree is a Valid Binary Search Tree \n");
    else
        printf("The Tree is not a Valid Binary Search Tree \n");

    return 0;
}
