#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Top View of the Binary Tree,
    Top View = Nodes that are visibile when a Binary Tree is seen from the top view.
    Each Left Child has it's line or index as index-1 and
    Right child has it's index as index+1


    TIME COMPLEXITY  : O(N) for traversing N number of nodes by Depth First Search ,
    SPACE COMPLEXITY : O(K) where K = number of top view nodes
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

void printTopView_Tree(struct BinaryNode* root)            //function to print the top view of the Binary Tree
{
    if(root == nullptr)                                    //if empty tree
        return;
    queue<pair<int,struct BinaryNode*>> q;                  //queue for storing node and it's line number as a pair<>
    map<int,struct BinaryNode*> topViewNodeMap;             //map for storing the first node with index i and do not store any other with index i in further traversal
    q.push({0,root});                                       //pushing the initial root node with initial index 0 as a pair to the queue

    while(!q.empty())               //while queue becomes empty
    {
        int index = (q.front()).first;          //index = queue front node pair's first value
        struct BinaryNode* currentNode = (q.front()).second;        //currentNode = queue front node pair's second value (Node reference*)

        auto isNodeExist = topViewNodeMap.find(index);          //check whether the key with value 'index' exist in the map

        if(isNodeExist == topViewNodeMap.end())                 //if no key with value 'index' doesn't exist then add the key = index , value = currentNode reference to the map
            topViewNodeMap[index] = currentNode;
        if(currentNode->leftNode)
            q.push({index-1,currentNode->leftNode});            //append the left child reference with it's index as index-1 as pair to the queue
        if(currentNode->rightNode)                              
            q.push({index+1, currentNode->rightNode});          //append the right child reference with it's index as index+1 as pair to the queue
        q.pop();    //pop the front node of the queue which is visited
    }

    for(auto a : topViewNodeMap)
        cout<<a.second->data<<" ";
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

    cout<<"\nTop View of the Binary Tree : ";
    printTopView_Tree(root);

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
