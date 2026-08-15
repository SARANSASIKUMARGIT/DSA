#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to construct a Binary Tree from Preorder + Inorder Traversal Array
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

struct BSTNode* constructTree(int* preOrderArray,int preOrderStart, int preOrderEnd,int *inOrderArray,int inOrderStart,int inOrderEnd)
{
    if(preOrderStart == preOrderEnd)
        return createNode( preOrderArray[preOrderStart] );
    int rootIndex = -1;
    for(int i=inOrderStart;i<=inOrderEnd;++i)
    {
        if(inOrderArray[i] == preOrderArray[preOrderStart])
        {
            rootIndex = i;
            break;
        }
    }
    if(rootIndex != -1)
    {
        struct BSTNode* root = createNode(inOrderArray[rootIndex]);
        root->left = constructTree(preOrderArray,preOrderStart+1,preOrderStart+(rootIndex-inOrderStart), inOrderArray,inOrderStart,rootIndex-1);
        root->right = constructTree(preOrderArray,preOrderStart+(rootIndex-inOrderStart)+1,preOrderEnd, inOrderArray,rootIndex+1,inOrderEnd);
        
        return root;
    }
    return NULL;

}

void inputPreorder_InorderArray(int** preOrderArray,int** inOrderArray,int n)
{
    *preOrderArray=(int*)malloc(n*sizeof(int));
    *inOrderArray = (int*)malloc(n*sizeof(int));
    if(*preOrderArray == NULL || *inOrderArray == NULL)
    {
        printf("Array Memory Allocation Failed . Please Try again \n");
        exit(1);
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter Preoder Node %d value : ",i);
        scanf("%d",(*preOrderArray)+i);
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter Inorder Node %d value : ",i);
        scanf("%d",*(inOrderArray)+i);
    }
}

void preOrderTraversal(struct BSTNode* root)
{
    if(root==NULL)
        return;
    printf("%d  ",root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{ 
    int n;
    printf("Enter the length of Traversal Array : ");
    scanf("%d",&n);

    int *preOrderArray=NULL,*inOrderArray = NULL;
    inputPreorder_InorderArray(&preOrderArray,&inOrderArray,n);
    struct BSTNode* root = constructTree(preOrderArray,0,n-1,inOrderArray,0,n-1);
    
    if(root==NULL)
    {
        printf("Couldn't Construct the Binary Tree, Verify the Preorder and Inorder Traversal Array \n");
        exit(1);
    }

    printf("PreOrder Traversal of the Tree :  ");
    preOrderTraversal(root);  
    
    


    return 0;
}
