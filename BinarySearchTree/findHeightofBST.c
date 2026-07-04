#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

/* Saran SK */

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

int leafCount=0;
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

struct BSTNode* deleteTree(struct BSTNode* root)
{
    if(root==NULL)
        return NULL;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    printf("Node Deleted \n");
    return NULL;
}

int max(int a,int b)
{
    return (a>b)?a:b;
}

int heightofBST(struct BSTNode* root)   //Function to calculate the longest path to a leaf node from the root node
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    return 1+ max(heightofBST(root->left),heightofBST(root->right));  //Recursive Approach
}


void main()
{

    int n,num;
    printf("Enter the number of nodes :  ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        printf("%d : ",i);
        scanf("%d",&num);
        root=insertNode(root,num);    //Inserting the node into BST and returning the address 
    }

    printf("\n Root : %d\n",root->data);  //Printing the value of the root node

    printf("Height of the Tree : %d",heightofBST(root));  //Finding the height of the Binary Search Tree by Recursive Approach
    

    root=deleteTree(root);
    if(root==NULL)
        printf("TREE IS EMPTY");

}
