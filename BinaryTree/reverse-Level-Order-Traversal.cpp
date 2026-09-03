#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print Nodes in the Reverse Level Order (Reverse of FIFO)

    TIME COMPLEXITY  : O(N) for traversing N number of nodes + N number of nodes from the stack,
    SPACE COMPLEXITY : O(N) for storing N number of nodes in the queue and stack
*/

struct BinaryNode                 //defining the structure of BinaryNode using struct 
{
    int data;                    //members of BinaryNode structure
    BinaryNode* leftNode;
    BinaryNode* rightNode;

    BinaryNode(int value) : data(value) , leftNode(nullptr) , rightNode(nullptr) {};            //constructor method to initialize members of the object
};

struct BinaryNode* insertNode(BinaryNode* root,int data)                        //Function to insert new node with value 'data' into the Binary Tree using BFS Traversal
{
    if(root == nullptr)                     //if tree is empty , then return create node with value 'data' and return as root
        return new BinaryNode(data);

    queue<BinaryNode*> q;                   //if tree is not empty, create a queue for BFS traversal of the tree to find the child that has 0 or 1 child by search in Level Order
    q.push(root);                           //pushing the root node to the queues
    while(!q.empty())
    {
        BinaryNode* frontNode = q.front();      
        if(frontNode->leftNode == nullptr)                  // if current node has no left child then create new node and return it as the left child of the current node and break the loop
        {
            frontNode->leftNode = new BinaryNode(data);
            break;
        }
        q.push(frontNode->leftNode);                    //if current node has left child push it to the queue
        if(frontNode->rightNode == nullptr)                 // if current node has no right child then create new node and return it as the right child of the current node and break the loop
        {
            frontNode->rightNode = new BinaryNode(data);        
            break;
        }
        q.push(frontNode->rightNode);                  //if current node has right child push it to the queue

        q.pop();       //pop the front node from the queue as we already visited it
    }
    while(!q.empty())       //pop all the remaining nodes in the queue if exist
        q.pop();
    return root;        //return the root node
}

void reverse_level_Order_Traversal(struct BinaryNode* root)                     //function to perform Reverse Level Order Traversal
{
    if(root == nullptr)
        return;
    queue<BinaryNode*> q;               //queue for storing nodes in Level Order (FIFO)
    stack<BinaryNode*> s;               //stack for storing nodes in Reverse Level Order (LIFO)

    q.push(root);                       //pushing the current node to the queue
    while(!q.empty())
    {
        BinaryNode* current = q.front();
        s.push(current);                        //pushing current front node of the queue to the stack
        if(current->leftNode)                   
            q.push(current->leftNode);          //pushing left node of the current front node
        if(current->rightNode)
            q.push(current->rightNode);         //pushing right node

        q.pop();             //popping the front node of the queue
    }

    cout<<"Reverse Level Order Traversal : ";
    while(!s.empty())
    {
        cout<<s.top()->data<<" ";             //printing the top node of the stack
        s.pop();                        //popping the top node
    }
    cout<<endl;
}

void deleteTree(BinaryNode* root)                           //function to deallocate all nodes of the tree from memory
{
    if(root == nullptr)
        return;
    deleteTree(root->leftNode);
    deleteTree(root->rightNode);
    delete root;
}


int main()
{
    struct BinaryNode* root = nullptr;

    int n,num;
    cout<<"Enter the number of nodes of the Binary Tree : ";

    cin>>n;                             //inputing number of nodes
    for(int i=0;i<n;++i)                                    
    {
        cout<<"Enter Node "<<i<<" value : ";
        cin>>num;   
        root=insertNode(root,num);              //inserting the data into the tree
    }

    reverse_level_Order_Traversal(root);                    //calling reverse level order function

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
