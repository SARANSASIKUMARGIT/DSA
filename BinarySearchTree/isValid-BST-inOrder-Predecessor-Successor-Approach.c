#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

/* Saran SK */

/*
    NOTE : This approach may fail in Deep BST but works fine for medium level BST ,
            The Optimal Approach is by Boundary Checking Method (check out in this current repo folder for /isValid-BST-Boundary-Checking-Approach.c )
    
    C Program to check whether a Binary Search Tree (BST) is valid or not ?
    A BST is valid only if for each node all the nodes on it's left are less than it and
    all the nodes on it's right are greater than it. 
    Otherwise , it is not a Valid BST.

    The Approach of this program is , It check every node that 
        if currentNode value is greater than it's inOrder Predecessor and current Value is less than it's inOrder Successor 
            then move to both left and right child and verify the same condition for it
        if node is null or leaf node 
            then return true;
        else 
            return false; 

    Inorder Predecessor : Largest Value on the Left Subtee,
    Inorder Successor   : Smallest Value on the right Subtree
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

int inorder_Predeccesor(struct BSTNode* root)                           //Function to find the greatest value node on the left SubTree of the current Node
{
    if(root==NULL)
        return 0;
    if(root->right==NULL)
        return root->data;
    return inorder_Predeccesor(root->right);
}

int inorder_Successor(struct BSTNode* root)                             //Function to find the smallest value node on the right SubTree of the current Node
{
    if(root==NULL)
        return 0;
    if(root->left==NULL)
        return root->data;
    return inorder_Successor(root->left);
}

bool isValidBST(struct BSTNode* root)
{
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)                       // if node is a leaf node
        return true;
    if(root->left != NULL && root->right != NULL)                   //if node is not a leaf node and have childs
    {
        int largestValueinLeftSubTree = inorder_Predeccesor(root->left);            //finding inorder Predecessor(largest value on left Subtree)
        if(largestValueinLeftSubTree >= root->data)                             //if true , then not a valid BST
            return false;
        int smallestValueinRightSubTree = inorder_Successor(root->right);           //finding inorder_succesor (smallest value on the right Subtree)
        if(smallestValueinRightSubTree <= root->data)                           //if true , then BST is not valid because only node with values greater than the current node can only be on the right subTree of the respective node
            return false;
        return isValidBST(root->left) && isValidBST(root->right);               //if the current node is a valid BST and then verify it's child validity by recursive call to both left and right Child
    }
    if(root->left != NULL)                          //if only left child exist
    {
        int largestValueinLeftSubTree = inorder_Predeccesor(root->left);
        if(largestValueinLeftSubTree >= root->data)
            return false;
        return isValidBST(root->left);
    }
    if(root->right != NULL)                         //if only right child exist
    {
        int smallestValueinRightSubTree = inorder_Successor(root->right);
        if(smallestValueinRightSubTree <= root->data)
            return false;
        return isValidBST(root->right);
    }
}


int main()
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

    struct BSTNode* node = fetchNode(root,10);              //fetching a node with specific value from the BST 
    if(node!=NULL)
        node->right= createNode(node->data -1);             //to perform manual invalid insertion into BST to test the function isValidBST()

    if(isValidBST(root))
        printf("The Tree is a Valid Binary Search Tree \n");
    else
        printf("The Tree is not a Valid Binary Search Tree \n");

    return 0;
}
