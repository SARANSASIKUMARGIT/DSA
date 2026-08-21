#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

                    /*   Saran SK    */

/*
    C Program to Deserialize a Tree,
    Serializing is the process of converting a Tree into a transmitted format e.g String,
    Deserializing is the process of constructing the tree from the serialized format (String -> Binary Tree)
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

struct BSTNode* deSerializeTree(char* str,int i,int current_Element_Index,int previous_non_NULL_Node_Count,int n)
{
    struct BSTNode* node=NULL;
    //skipping characters except numbers and # (null node)
    while(i<n && ((str[i]<48 || str[i]>57) && str[i]!='#'))
        ++i;
    int sum=0;
    bool isNum=false, isLeftChildFound = false, isRightChildFound = false;
    while(i<n && (str[i]>=48 && str[i]<=57))
    {
        sum *= 10;
        sum+=(str[i]-48);
        isNum=true;
        ++i;
    }
    if(isNum)
        node=createNode(sum);
    else
        return NULL;

    int index_of_leftChild_of_CurrentNode = (previous_non_NULL_Node_Count * 2) + 1;
    int index_of_rightChild_of_CurrentNode = (previous_non_NULL_Node_Count * 2) + 2;
    previous_non_NULL_Node_Count++;
    if(index_of_leftChild_of_CurrentNode >= n)
        return node;
    
    int count_of_next_nodes = 1;
    while(i<n && (!isLeftChildFound || !isRightChildFound))
    {
        while(i<n && ((str[i]<48 || str[i]>57)&& str[i]!='#'))
            ++i;
        if(i>=n)
            return node;
        int in=i,sum=0;
        isNum=false;
        while(str[i]>=48 && str[i]<=57)
        {
            sum*=10;
            sum+= (str[i]-48);
            isNum=true;
            ++i;
        }
        if(isNum)
        {
            if(current_Element_Index + count_of_next_nodes == index_of_leftChild_of_CurrentNode)
            {
                isLeftChildFound = true;
                node->left= deSerializeTree(str,in,current_Element_Index + count_of_next_nodes, previous_non_NULL_Node_Count, n);
            }
            count_of_next_nodes++;
            previous_non_NULL_Node_Count++;
        }
        else if(i>=n)
            return node;
        else if(str[i]=='#')
        {
            if(current_Element_Index + count_of_next_nodes == index_of_leftChild_of_CurrentNode)
            {
                node->left = NULL;
                isLeftChildFound = true;
            }
            count_of_next_nodes++;
        }

        if(i<n && isLeftChildFound)
        {
            while(i<n && ((str[i]<48 || str[i]>57) && str[i]!='#'))
                ++i;
            if(i>=n)
                return node;
            int in = i, sum = 0;
            isNum = false;
            while(i<n && (str[i]>=48 && str[i]<=57))
            {
                sum*=10;
                sum+=(str[i]-48);
                isNum=true;
                ++i;
            }
            isRightChildFound = true;
            if(isNum)
            {
                node->right = deSerializeTree(str,in, index_of_leftChild_of_CurrentNode + 1,previous_non_NULL_Node_Count,n);
            }
            else if(i>=n || str[i]=='#')
                node->right=NULL;
            return node;

        }
            
    }
    
    return node;
}

void inOrderTraversal(struct BSTNode* root)
{
    if(root==NULL)
        return;
    inOrderTraversal(root->left);
    printf("%d ",root->data);
    inOrderTraversal(root->right);
}

int main()
{ 
       struct BSTNode* root=NULL;
       char str[30];
       printf("Enter the Serialized Tree String : ");
       fgets(str,sizeof(str),stdin);
       root = deSerializeTree(str,0,0,0,strlen(str));

       printf("\n Inorder Traversal of BST : ");
       inOrderTraversal(root);
    


    return 0;
}
