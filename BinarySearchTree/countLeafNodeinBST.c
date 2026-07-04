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

void inorderTraversal(struct BSTNode* root)   //Function to perform Inorder Traversal of the BST  left node -> current node -> right node
{
    if(root==NULL)
        return;
    inorderTraversal(root->left);
    printf("%d - ",root->data);
    inorderTraversal(root->right);
}

void countLeafNode(struct BSTNode* root)
{
    if(root==NULL)
        return;
    countLeafNode(root->left);
    countLeafNode(root->right);
    if(root->left == NULL && root->right == NULL)  //if the current node has no left and right child then it is a leaf node 
        leafCount++;
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

    inorderTraversal(root);

    printf("\n Root : %d\n",root->data);  //Printing the value of the root node
    
    countLeafNode(root);
    printf("\nNumber of Leaf Node :  %d\n",leafCount);

    root=deleteTree(root);
    if(root==NULL)
        printf("TREE IS EMPTY");

}
