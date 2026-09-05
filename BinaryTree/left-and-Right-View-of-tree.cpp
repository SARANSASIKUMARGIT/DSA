#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Left View and Right View of the Binay Tree,
    Left View  = Nodes that are visible from the left view of the Binary Tree,
    Right View = Nodes that are visible from the right view of the Binary Tree

    TIME COMPLEXITY  : O(N) for traversing N number of nodes,
    SPACE COMPLEXITY : O(K) extra space for storing nodes of level of the tree in the queue,
                        where K = maximum number of nodes in a level
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

void printLeftViewofTree(struct BinaryNode* root)
{
    if(root == nullptr)                 //if tree is empty return 
        return;
    queue<BinaryNode*> q;               //queue for storing nodes in level order
    q.push(root);                       //pushing root node to the queue

    while(!q.empty())
    {
        BinaryNode* current = q.front();        
        cout<<current->data << " ";             //printing the value of front node of the queue
        int currentLevelNodes = q.size();       //Getting the current level node count which is the size of the queue
        for(int i=1;i<=currentLevelNodes;++i)
        {
            current = q.front();            //for each node in the current level , push it's child to the queue and pop itself from the queue
            if(current->leftNode)
                q.push(current->leftNode);
            if(current->rightNode)
                q.push(current->rightNode);
            q.pop();
        }
    }
}

void printRightViewofTree(struct BinaryNode* root)
{
    if(root == nullptr)                 //if tree is empty return 
        return;
    queue<BinaryNode*> q;               //queue for storing nodes in level order
    q.push(root);                       //pushing root node to the queue

    while(!q.empty())
    {
        BinaryNode* current = q.front();        
        cout<<current->data << " ";             //printing the value of front node of the queue
        int currentLevelNodes = q.size();       //Getting the current level node count which is the size of the queue
        for(int i=1;i<=currentLevelNodes;++i)
        {
            current = q.front();            //for each node in the current level , push it's child to the queue and pop itself from the queue
            if(current->rightNode)
                q.push(current->rightNode);
            if(current->leftNode)
                q.push(current->leftNode);
            q.pop();
        }
    }
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

    cout<<"Left View of the Binary Tree : ";
    printLeftViewofTree(root);

    cout<<"\nRight View of the Binary Tree : ";
    printRightViewofTree(root);

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
