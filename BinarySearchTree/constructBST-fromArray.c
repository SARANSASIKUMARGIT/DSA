#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to construct BST fron the sorted array
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

void inOrderTraversal(struct BSTNode* root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);

}

void deleteBST(struct BSTNode* root)
{
    if(root==NULL)
        return;
    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}

int main()
{ 
    int n,num,*arr=NULL;
    printf("Enter the number of elements in array :  ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    if(arr == NULL)
    {
        printf("Dynamic Memory Allocation for Array Failed.. Please Try Again\n");
        exit(1);
    }
    printf("Please Enter Array Elements in Sorted Order \n\n");
    for(int i=0;i<n;++i)
    {
        printf("Enter element %d : ",i);
        scanf("%d",arr+i);
    }

    int middleIndex = (n-1)/2;

    for(int i=middleIndex;i>=0;--i)
        root=insertNode(root,arr[i]);

    for(int i=middleIndex+1;i<n;++i)
        root=insertNode(root,arr[i]);

    printf("Inorder Traversal of the BST constructed from Array : ");
    inOrderTraversal(root);


    deleteBST(root);
    root = NULL;







    return 0;
}
