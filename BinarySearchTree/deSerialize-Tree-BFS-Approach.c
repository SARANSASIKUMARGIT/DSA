#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

                    /*   Saran SK    */

/*
    C Program to Deserialize a Tree,
    Serializing is the process of converting a Tree into a transmitted format e.g String,
    Deserializing is the process of constructing the tree from the serialized format (String -> Binary Tree)

    In this Program I have Used Binary Search Tree(BST) Data Structure for inserting the nodes into the tree more conveniently,
    I've Serialized the Tree by Appending the nodes of the Trees with Breadth-First Traversal (BFS) with commma ',' as separator between nodes using Queue,
    After Serializing the Tree into a String , I've Deserializing the String to construct Tree Back Again by Selecting Each Node from the serialized string and 
    mapping it with it's left and right child from the adjacent substring by extracting the node as a string and converting them to an integer and creating the
    BSTNode and pushing them in BFS order into the Queue.
*/

struct BSTNode *root=NULL;   //Pointer that stores the memory address of the root node of the binary search tree (initially NULL)

struct BSTNode               //Defining the structure of node in the binary search Tree
{
    int data;                   //Variable for storing value of the node
    struct BSTNode *left;       //Pointer of type node that stores the memory address of its left child
    struct BSTNode *right;      //Pointer of type node that stores the memory address of its right child
};

//Declaring Structure of Queue Node
struct queue
{
    struct BSTNode* node;
    struct queue* next;
};

struct queue *front = NULL, *back=NULL;                 //pointers to first and last node of the queue

struct queue* createQueueNode(struct BSTNode* root)     //Function to create a New Queue Node at heap 
{
    struct queue* tempNode = (struct queue*)malloc(sizeof(struct queue));
    tempNode->node=root;
    tempNode->next=NULL;
    return tempNode;
}

void push2Queue(struct BSTNode* root)           //Function to push a New Queue at the end of the Queue
{
    struct queue* tempNode = createQueueNode(root);
    if(front==NULL)                             //if Queue is empty , then the new node is the first and last element of the Queue
    {
        front=tempNode;
        back=tempNode;
    }
    else if(front==back)                        //if Queue has only One Node
    {
        back=tempNode;
        front->next = back;
    }
    else
    {
        back->next = tempNode;                  //if Queue has more than 1 Node , then adding the new node at the end
        back=tempNode;
    }
}

void popFromQueue()                             //Function to pop the node at the front of the Queue
{
    if(front!=NULL)
    {
        struct queue* tempNode = front;
        if(front==back)
            back=NULL;
        front=front->next;
        free(tempNode);
    }
}

bool emptyQueue()                       //Function to check whether a Queue is EMPTY or not
{
    return (front==NULL)? true : false;
}

void clearQueue()                       //Function to completely clear a Queue
{
    while(front!=NULL)
    {
        struct queue* tempNode = front;
        front=front->next;
        free(tempNode);
    }
    back=NULL;
}

struct BSTNode* createNode(int data)        //Function to create a new node at runtime in heap memory
{
    struct BSTNode* newNode=(struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

    return newNode;
}

struct BSTNode* insertNode(struct BSTNode* root, int data)
{
    if(root==NULL)
        return createNode(data);
    if(data<root->data)
        root->left = insertNode(root->left,data);
    else
        root->right = insertNode(root->right,data);
    return root;
}

void append2String(char* str,int* index,char* temp)                 //Function to append string to the given string reference
{
    int len=strlen(temp);
    for(int i=0;i<len;++i)
        str[(*index)++]=temp[i];
    str[(*index)++] = ',';
}

char* integer2String(int num)               //Function to convert integer to string
{
    char *str='\0',i=0;
    str=(char*)malloc(10*sizeof(char));

    do{
        str[i++] = (char)(48 + (num%10));
        num/=10;
    }while(num);
    for(int m=0,n=i-1; m<n ; ++m,--n)
    {
        char temp=str[m];
        str[m]=str[n];
        str[n] = temp;
    }
    str[i]='\0';
    return str;
}

char* serializeTree(struct BSTNode* root)               //Function to convert the TREE into a String
{
    if(root==NULL)                                      //if Tree is empty , return empty string ''
    {
        char* str=(char*)malloc(2*sizeof(char));
        strcpy(str,"");
        return str;
    }
    char* str=(char*)malloc(50*sizeof(char));           //allocate memory for the serialize string
    int index=0;
    push2Queue(root);                                   //Push the root node to the QUEUE
    while(!emptyQueue())
    {
        struct BSTNode* tempBSTNode = front->node;      //fetching the BST node from the Front Node of the QUEUE
        if(tempBSTNode==NULL)                           //if node is null add '#' to the serialize string
            append2String(str,&index,"#");
        else
        {   //if node is not Null , then append the data of the current node to the serialize string 
            char* numStr= integer2String(tempBSTNode->data);
            append2String(str,&index,numStr);
            push2Queue(tempBSTNode->left);          //Pushing the left and Right Child of the current node to the Queue, for BFS traversal
            push2Queue(tempBSTNode->right);
            free(numStr);                           //deallocating the string memory
        }
        popFromQueue();    // Pop the front node of the Queue for each Iteration
    }
    str[index-1]='\0';              //removing the extra comma at the serializeString
    
    return str;                     //Returning the Serialize String
}

int string2Integer(char* str)           //Function to convert string to integer
{
    int sum=0;
    for(int i=0;i<strlen(str);++i)
        sum = (sum*10) + (str[i]-48);
    return sum;
}

char* tokenString(char* str,int *i, char delimeter)         //function to return first substring before the delimeter
{
    if(*i >= strlen(str))
        return "";
    int tempPointer=0;
    char *temp= (char*)malloc(10*sizeof(char));
    while(*i < strlen(str) && str[*i]!=delimeter)
    {
        temp[tempPointer++]=str[(*i)++];
    }
    (*i)++;
    temp[tempPointer]='\0';
    return temp;
}

struct BSTNode* deSerializeTree(char* serializeString)                  //Function to Construct The TREE back from the Serialize Tree
{
    int index = 0,len = strlen(serializeString);
    if(len==0)
        return NULL;
    clearQueue();                   //clear previously created Queue Completely
    char *buf = tokenString(serializeString,&index,',');            //Fetching the first node before the ','
    if(strcmp(buf,"#")==0)      // if null node
    {
        free(buf);
        return NULL;
    }
    int data = string2Integer(buf);             // if not a NUll node then crete a BSTNode and push into the Queue
    struct BSTNode* root = createNode(data);
    free(buf);
    push2Queue(root);
    while(!emptyQueue())                        //While the Queue becomes empty
    {
        struct BSTNode* node = front->node;     //Fetching the BSTNode from the Front Queue Node
        char* leftChild = tokenString(serializeString,&index,',');              //Fetching the left child substring (left child) before ','
        if(strcmp(leftChild,"#")==0)            // if left child is a NULL node
            node->left = NULL;
        else
        {       //if left child is NOT A NULL node
            data = string2Integer(leftChild);
            struct BSTNode* leftNode = createNode(data);            //create BSTNode for left child and map it to it's parent 
            node->left = leftNode;
            push2Queue(leftNode);                                   //pushing the left child to the Queue
        }
        char* rightChild = tokenString(serializeString,&index,',');         //Fetching the right child substring (right child) before ','
        if(strcmp(rightChild,"#")==0)       //if right child is a NULL node
            node->right = NULL;
        else
        {       //if right child is NOT A NULL node
            data = string2Integer(rightChild);
            struct BSTNode* rightNode = createNode(data);           //create a BSTNode for right child and map it to the current node (parent node)
            node->right = rightNode;
            push2Queue(rightNode);              //Pushing the right child to the end of the Queue
        }
        free(leftChild);                    //deallocating memory allocated for left and right child node
        free(rightChild);

        popFromQueue();                     //Popping the front node from the Queue , as we no more need it
    }
    return root;                            //returning the root node of the Binary Tree

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
    int n,num;
    struct BSTNode* root1=NULL,*root2=NULL;
    printf("Enter the number of nodes of Binary Tree : ");
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {   //inserting nodes into the TREE1
        printf("Enter the Node %d : ",i);
        scanf("%d",&num);
        root1=insertNode(root1,num);
    }

    printf("\nInorder Traversal Before Serializing : ");
    inOrderTraversal(root1);                //Traversing the TREE(BST1) by Inorder 
    printf("\n");

    char *serializeString = serializeTree(root1);       //converting the Tree into a String

    root2 = deSerializeTree(serializeString);           //Converting the String Back into TREE (BST2)

    printf("\nInorder Traversal After Deserializing : ");
    inOrderTraversal(root2);                            //Travering the Tree (BST2) constructed from The String

    return 0;
}
