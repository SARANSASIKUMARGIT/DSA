#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to construct a Binary Tree from Preorder + Inorder Traversal Array
*/

struct BSTNode *root=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initially NULL)
int *preOrderArray=NULL,*inOrderArray = NULL;

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

struct BSTNode* constructTree(int low,int preOrderPointer,int inOrderPointer,int endRange ,int high)
{
    if(preOrderArray[preOrderPointer] == inOrderArray[inOrderPointer])
    {
        struct BSTNode* root = createNode(preOrderArray[preOrderPointer]);
        if(preOrderPointer + 1 <= high)
        {
            int leftNode = preOrderArray[preOrderPointer+1];
            int leftNodeindex = -1;
            for(int i=inOrderPointer-1;i>=low;--i)
            {
                if(inOrderArray[i]==leftNode)
                {
                    leftNodeindex = i;
                    break;
                }
            }
            if(leftNodeindex != -1)
                root->left = constructTree(low,preOrderPointer+1,leftNodeindex,inOrderPointer,high);

            int rightNode = preOrderArray[preOrderPointer + inOrderPointer + 1];
            int rightNodeindex = -1;
            for(int i=inOrderPointer+1;i<=endRange;++i)
            {
                if(inOrderArray[i] == rightNode)
                {
                    rightNodeindex = i;
                    break;
                }
            }
            if(rightNodeindex != -1)
                root->right= constructTree(inOrderPointer+1, preOrderPointer + inOrderPointer + 1,rightNodeindex,endRange,high);
        }

        return root;
    }
    return NULL;
}

void inputPreorder_InorderArray(int n)
{
    preOrderArray=(int*)malloc(n*sizeof(int));
    inOrderArray = (int*)malloc(n*sizeof(int));
    if(preOrderArray == NULL || inOrderArray == NULL)
    {
        printf("Array Memory Allocation Failed . Please Try again \n");
        exit(1);
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter Preoder Node %d value : ",i);
        scanf("%d",preOrderArray+i);
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter Inorder Node %d value : ",i);
        scanf("%d",inOrderArray+i);
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
    int n,rootNodeIndex=-1;
    printf("Enter the length of Traversal Array : ");
    scanf("%d",&n);

    inputPreorder_InorderArray(n);
    for(int i=0;i<n;++i)
    {
        if(inOrderArray[i] == preOrderArray[0])
        {
            rootNodeIndex = i;
            break;
        }
    }

    if(rootNodeIndex == -1)
    {
        printf("Root Node %d Not found in Inorder Traversal Array . Enter a valid Array \n");
        exit(1);
    }

    root=constructTree(0,0,rootNodeIndex,n-1,n-1);
    if(root==NULL)
        printf("Tree is Empty . Construction Failed \n");
    preOrderTraversal(root);  
    
    


    return 0;
}
