#include<stdio.h>
#include<stdlib.h>  

        /*    Saran SK     */

/*
    C program to create,insert Nodes in Binary Search Tree (BST) Data Structure and 
    invert(mirroring) the BST 
*/

struct BSTNode                          //declaring structure of Binary Search Tree Node
{
    int data;
    struct BSTNode *left,*right;
};

struct BSTNode* root=NULL;   
struct BSTNode* invertRoot=NULL;      

struct BSTNode* createBSTNode(int value)            
{
    struct BSTNode* node=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    node->data=value;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct BSTNode* insertNode(struct BSTNode* root,int value)                  //Function to insert new Node in BST
{
    if(root==NULL)
        return createBSTNode(value);
    if(value<=root->data)
        root->left=insertNode(root->left,value);
    else
        root->right=insertNode(root->right,value);
    return root;
}

struct BSTNode* invertBST(struct BSTNode* root)
{
    if(root==NULL)
        return NULL;
    struct BSTNode* currentNode = createBSTNode(root->data);
    currentNode->right=invertBST(root->left);
    currentNode->left=invertBST(root->right);
    return currentNode;
}

void printBST(struct BSTNode* root)
{
    if(root==NULL)
        return;
    printBST(root->left);
    printf("%d ",root->data);
    printBST(root->right);   
}

void main()
{
    int n,num;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);                                 //Inputing the number of nodes of BST 
    for(int i=0;i<n;++i)
    {
        printf("Enter Node %d value : ",i);
        scanf("%d",&num);
        root=insertNode(root,num);                  //inserting data as BST Node in Binary Search Tree by maintaining the property of BST
    }

    printf("Original Tree  :  ");
    printBST(root);
    printf("\n");
    
    invertRoot=invertBST(root);
    printf("Invert Tree    :  ");
    printBST(invertRoot);
    printf("\n");

}
