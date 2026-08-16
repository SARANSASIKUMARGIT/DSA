#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

/* Saran SK */

/*
    C Program to construct a Binary Tree from Preorder + Inorder Traversal Array,
    Preorder Traversal = Root Node -> Left Node -> Right Node,
    Inorder  Traversal = Left Node -> Root Node -> Right Node,
    In the Inorder Array , all the elements(node) to the left of the root node are the nodes of the left Subtree of root node AND to the right elements are node of right Subtree,
    In the Preorder Array , always the first element is the root element, followed by all left subtrees then all it's right Subtree nodes.

    Approach : 
        *The First Element of the Preorder Array is the root node ,
        *Find the root node in the Inorder Array (rootNodeindex) ,
        *Count the number of elements left to the root node in Inorder array = LN
        *Count the number of elements right to the root node in Inorder array = RN
        *Create Binary Node with Value of Element InorderArray[rootNodeindex] 
        *Node -> left = ConstructTree(preArray , preStart,preEnd, inArray, inStart,inEnd)
        *Node ->right = ConstructTree(preArray, preStart,preEnd, inArray, inStart,inEnd)

        NOTE : THIS EXPLANATION MAY FEEL AMBIGIOUS BUT IT WILL BE UNDERSTOOD AFTER PRACTICAL / DRY RUN EXAMPLE BY YOURSELF
        "If There are N1 number of elements to the left of root element in Inorder array, then in the Preorder array after the root element the first N1 elements are left subtree nodes,
        and if there are N2 number of elements to the right of the root element in the Inorder Array, then there are N2 number of right subtree nodes after the N1 number of left subtrees node in the Preorder Array"
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

    if(preOrderStart == preOrderEnd)        //if only one node remaining
        return createNode( preOrderArray[preOrderStart] );
    int rootIndex = -1;
    for(int i=inOrderStart;i<=inOrderEnd;++i)           //Loop to find the root node in the inorder array
    {
        if(inOrderArray[i] == preOrderArray[preOrderStart])
        {               
            rootIndex = i;                      //if root node is found , store the index and break the loop
            break;
        }
    }
    if(rootIndex != -1)                 //if root node found in the loop traversal
    {
        struct BSTNode* root = createNode(inOrderArray[rootIndex]);             //create Binary Node for element at index 'rootIndex' at inorder traversal array
        root->left = constructTree(preOrderArray,preOrderStart+1,preOrderStart+(rootIndex-inOrderStart), inOrderArray,inOrderStart,rootIndex-1);        //pointing the left subtree by recursion
        root->right = constructTree(preOrderArray,preOrderStart+(rootIndex-inOrderStart)+1,preOrderEnd, inOrderArray,rootIndex+1,inOrderEnd);           //pointing the righ subtree by recursion
        
        return root;            //finally return the root node to the caller function
    }
    return NULL;            //if unexpected behaviour , return NULL

}

void inputPreorder_InorderArray(int** preOrderArray,int** inOrderArray,int n)
{
    //Function to create Dynamic Array of Preorder and Inorder by dereferencing the memory address of the pointer
    *preOrderArray=(int*)malloc(n*sizeof(int));
    *inOrderArray = (int*)malloc(n*sizeof(int));
    if(*preOrderArray == NULL || *inOrderArray == NULL)
    {
        printf("Array Memory Allocation Failed . Please Try again \n");
        exit(1);
    }
    //Inputing values for Preorder and Inorder Traversal Array
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

    int *preOrderArray=NULL,*inOrderArray = NULL;                       //pointers to point to the memory address of dynamic array
    inputPreorder_InorderArray(&preOrderArray,&inOrderArray,n);         //function to create dynamic array of n elements with passing both pointer's address    
    
    struct BSTNode* root = constructTree(preOrderArray,0,n-1,inOrderArray,0,n-1);       //function to construct the Binary Tree and return the root node
    
    if(root==NULL)          //if TREE creation failed
    {
        printf("Couldn't Construct the Binary Tree, Verify the Preorder and Inorder Traversal Array \n");
        free(preOrderArray);
        free(inOrderArray);
        free(root);
        exit(1);
    }

    printf("PreOrder Traversal of the Tree :  ");
    preOrderTraversal(root);            //printing preOrderTraversal of the Binary Node

    //Dealloacting the dynamic memory after use
    free(preOrderArray);
    free(inOrderArray);
    free(root);
    
    


    return 0;
}
