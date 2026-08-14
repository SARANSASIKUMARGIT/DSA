#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to find the K th Largest Node in a BST,
    In this Program , I have performed Reverse Inorder Traveral (right Node -> current Node -> left Node) by recursion.
    The Count of the Current Node = Number of Nodes on it's Right Subtree + 1,
    Therefore , A Node verifies whether it's count == k by counting the number of nodes on it's right Subtree,
    if the current Node count != Count , then move to the left Node by recursion where the same approach is followed there as well,
    if a node is null, then the return value is Previous Node count because the current node is NULL and can be counted as a Node,

    if root is null -> return NULL
    else if n==0 -> print "Tree is Empty"
    else if (k<=0) -> print "Invalid K value"
    else if k<=n 
        finding K th largest node is possible, print the K Largest Node
    else
        printing failure message
*/

struct BSTNode *root=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initially NULL)

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

struct BSTNode* Kth_LargestNode = NULL;

struct BSTNode* findKthLargestNode(struct BSTNode* root,int k,int* count)
{
    if(root==NULL)                  // if node is null
        return NULL;
    struct BSTNode* right = findKthLargestNode(root->right,k,count);              //research Kth largest node on right subtree
    if(right!=NULL)
        return right;               //if K th largest node found in right Subtree return the reference
    (*count)++;                     // incrementing the node count by 1 (count of current Node)
    if(count == k)                  
        return root;                //if current Node is the K th Node , then return the reference of Current Node

    return findKthLargestNode(root->left,k,count);              // if still K th Largest Node is not found , then find in Left Subtree by recursion

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

    int k;
    printf("Enter the value of K : ");
    scanf("%d",&k);

    if(n==0)
        printf("Tree is Empty . Please Enter Nodes into the BST \n");
    else if(k<=0)
        printf("Invalid K value. Please Enter a Valid Value of K (1 <= K <= n)")
    else if(k<=n)
    {
        int isNodeFound = findKthLargestNode(root,k,0);
        printf("K th Largest Node is %d \n",Kth_LargestNode->data);
    }
    else 
        printf("K Value is greater than the number of Nodes . Please enter value less than or equal to the number of nodes in the Tree");




    return 0;
}
