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

void postorderTraversal(struct BSTNode* root) //Function to perform Postorder Traversal of the BST  left node -> right node,-> current node
{
    if(root==NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d - ",root->data);
}

void preorderTraversal(struct BSTNode* root) //Function to perform Preorder Traversal of the BST  root node -> left node -> right node 
{
    if(root==NULL)
        return;
    printf("%d - ",root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
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
    printf("\n");
    preorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");
    printf("\n Root : %d\n",root->data);  //Printing the value of the root node

    root=deleteTree(root);
    if(root==NULL)
        printf("TREE IS EMPTY");

}
