#include<stdio.h>
#include<stdlib.h>  

        /*    Saran SK     */

/*
    C program to create,insert Nodes in Binary Search Tree (BST) Data Structure and 
    pushing the nodes of BST into stack by descending order , so that printing the value of stack prints the node in ascending order
*/

struct BSTNode                          //declaring structure of Binary Search Tree Node
{
    int data;
    struct BSTNode *left,*right;
};

struct stackNode                        //declaring structure of Stack Node
{
    struct BSTNode *bstNode;
    struct stackNode* next;
};

struct stackNode* top=NULL;         //pointer to store the memory address of the top node of the stack
struct BSTNode* root=NULL;          //pointer to store the memory address of the root node of the Binary Search Tree

struct stackNode* createStackNode(struct BSTNode* bstNode)          //Function to create stackNode at runtime and returns it
{
    struct stackNode* node=(struct stackNode*)malloc(sizeof(struct stackNode));
    node->bstNode=bstNode;
    node->next=NULL;
    return node;
}

void pushStackNode(struct BSTNode* bstNode)                 //Function to push BSTNode into stack
{   
    if(bstNode!=NULL)
    {
        if(top==NULL)
            top=createStackNode(bstNode);
        else
        {
            struct stackNode* newNode=createStackNode(bstNode);
            newNode->next=top;
            top=newNode; 
        }
    }
}


void popStackNode()                             //Function to pop top node of the stack
{
    if(top!=NULL)
    {
        struct stackNode* tempNode=top;
        top=top->next;
        free(tempNode);
    }
}

void displayNodeFromStack()                 //Function to display node from the stack by printing the value of top node and popping it
{
    while(top!=NULL)
    {
        printf("%d ",(top->bstNode)->data);
        popStackNode();
    }
}

struct BSTNode* createBSTNode(int value)            //Function to create BSTNode at runtime and returns it to the caller
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

void pushBSTNodetoStack(struct BSTNode* root)                   //Function to push BSTNode into stack from descending order (for printing in ascending order)
{
    if(root!=NULL)
    {
        pushBSTNodetoStack(root->right);
        pushStackNode(root);
        pushBSTNodetoStack(root->left);
    }
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

    pushBSTNodetoStack(root);                      //calling for pushing BSTNodes into descending order into the stack
    printf("Nodes from Binary Search Tree in Sorted Order : ");               
    displayNodeFromStack();                        //displaying the value of top node of the stack until it becomes NULL

}
