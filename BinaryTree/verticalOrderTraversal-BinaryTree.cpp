#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Nodes in Vertical Index Order in a Binary Tree,
    Each Left Child has it's line or index as index-1 and
    Right child has it's index as index+1


    TIME COMPLEXITY  : O(N) for traversing N number of nodes by Breadth First Traversal ,
    SPACE COMPLEXITY : O(N) for storing the vector(value) of nodes with their vertices as index(key)
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

void verticalOrderTraversal(struct BinaryNode* root)          //function to print the Nodes in Vertical Index Order
{
    if(root == nullptr)             //if tree is empty
        return;

    queue<pair<int,struct BinaryNode*>> q;                             //queue for storing pair of <index , Node*>
    map<int,vector<struct BinaryNode*>> verticesNodeMap;        //Ordered Map to store nodes of same vertical index in an array (vector)

    q.push({0,root});       //push root node with index=0 initially
    while(!q.empty())
    {
        int index = q.front().first;                            //fetching index of front element in queue
        struct BinaryNode* currentNode = q.front().second;      //fetching front node in the queue
        q.pop();                                                //pop the current front element 
        
        auto isVerticeExistinMap = verticesNodeMap.find(index);     //find whether the vertice 'index' exist in the map
        if(isVerticeExistinMap == verticesNodeMap.end())            //if key'index' doesn't exist in map  , then initalize the vector with current node
            verticesNodeMap[index] = {currentNode};
        else
            verticesNodeMap[index].push_back(currentNode);          //if the vertice(key) already exist append the vector with current node

        if(currentNode->leftNode)                                   //push left and right child with pair of index-1 and index+1 respectively
            q.push({index-1,currentNode->leftNode});    
        if(currentNode->rightNode)
            q.push({index+1,currentNode->rightNode});
    }

    for(auto a : verticesNodeMap)                       //fetching each key,value(index:vector) pair from the ordered map
    {
        cout<<"Vertical Index "<<a.first<<" : ";       
        for(auto node : a.second)
            cout<<node->data<<" ";                      //print the value of node in the vector
        cout<<endl;
    }
    
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

    verticalOrderTraversal(root);               //function to print the nodes in vertical index order

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}'Review and verify test cases'
