#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to Print the Boundary Nodes of the Binary Tree


    TIME COMPLEXITY  : O(N) for traversing N number of nodes by Breadth First Traversal ,
    SPACE COMPLEXITY : O(K) where K = number of Boundary nodes
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

void deleteTree(BinaryNode* root)                           //function to deallocate all nodes of the tree from memory
{
    if(root == nullptr)
        return;
    deleteTree(root->leftNode);
    deleteTree(root->rightNode);
    delete root;
}

void printBoundaryNodes_BinaryTree(struct BinaryNode* root)         //function to print the Boundary nodes of the binary tree
{
    if(root == nullptr)                 //return if tree is empty
        return;
    queue<struct BinaryNode*> q;
    int index = -1;                     //intial pointer 
    vector<int> res;                    //vector to store boundary nodes in respective order
    q.push(root);                       //push root node to the queue

    while(!q.empty())                   //until queue gets empty
    {
        int noOfCurrentLevelNodes = q.size(),idx=1;     //number of nodes in current level & idx = counter for inserting null nodes from the current index pointer into the result vector
        for(int i=1;i<=noOfCurrentLevelNodes;++i)
        {
            struct BinaryNode* currentNode = q.front();
            q.pop();
            if(i==1)                            //if first node of the level
            {
                ++index;                        //increment the index pointer and insert the data of current node to the result vector
                res.insert(res.begin()+index,currentNode->data);
            }
            else if(currentNode->leftNode==nullptr && currentNode->rightNode==nullptr)          //if node is null node
            {
                res.insert(res.begin()+index+idx,currentNode->data);
                ++idx;          //increment the counter after every null node data is inserted into the result vector 
                                //for inserting next null node data of the current level to next position of the latest inserted element
            }
            else if(i==noOfCurrentLevelNodes)           //if current node is the last node of the current level
                res.insert(res.begin()+index+1,currentNode->data);
            
            if(currentNode->leftNode)               //push left child of current node
                q.push(currentNode->leftNode);
            if(currentNode->rightNode)              //push right child of current node
                q.push(currentNode->rightNode);
        }
    }

    cout<<"Boundary Value Nodes : ";
    for(auto it=res.begin();it!=res.end();++it)     //print the Boundary Node's values
        cout<<*it<< " ";
    cout<<endl;
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

    printBoundaryNodes_BinaryTree(root);

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
