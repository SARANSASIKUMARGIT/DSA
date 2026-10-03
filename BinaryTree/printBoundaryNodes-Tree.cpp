#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Boundary Nodes of the Binary Tree


    TIME COMPLEXITY  : O(N) for traversing N number of nodes,
    SPACE COMPLEXITY : O(k) for storing k number of boundary nodes in a vector
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

bool isLeafNode(struct BinaryNode* root)
{
    if(root==nullptr || (root->leftNode==nullptr && root->rightNode==nullptr))          //if current node is null or leaf node
        return true;
    return false;
}

void preorderTraversal(struct BinaryNode* root, vector<int>& res)
{
    if(root==nullptr)
        return;
    if(isLeafNode(root))                    //check if current node is a leaf node
        res.push_back(root->data);
    preorderTraversal(root->leftNode,res);      //moving to left subtree
    preorderTraversal(root->rightNode,res);     //moving to right subtree
}

void boundaryTraversal(struct BinaryNode* root,vector<int>& res)
{
    if(root==nullptr)
        return;
    if(isLeafNode(root))
    {
        res.push_back(root->data);
        return;
    }
    res.push_back(root->data);                  //pushing root node's data to the result vector
    struct BinaryNode* current = root;
    current=current->leftNode;
    //pushing left boundary node's data to the result vector
    while(current)
    {
        if(!isLeafNode(current))                //check if current node is a leaf node
            res.push_back(current->data);
        if(current->leftNode)
            current = current->leftNode;
        else
            current = current->rightNode;
    }

    //pushing leaf node's value to the result vector
    preorderTraversal(root,res);       

    stack<int> rightBoundaryNodes;         //stack for storing right boundary nodes from top to bottom
    current= root->rightNode;

    //pushing right boundary node's to the result vector
    while(current)
    {
        if(!isLeafNode(current))                        //check if current node is a leaf node
            rightBoundaryNodes.push(current->data);
        if(current->rightNode)
            current = current->rightNode;
        else
            current = current->leftNode;        
    }

    while(!rightBoundaryNodes.empty())
    {
        int currentNodeValue = rightBoundaryNodes.top();
        rightBoundaryNodes.pop();
        res.push_back(currentNodeValue);
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
    vector<int> res;

    int n,num;
    cout<<"Enter the number of nodes of the Binary Tree : ";

    cin>>n;                             //inputing number of nodes
    for(int i=0;i<n;++i)                                    
    {
        cout<<"Enter Node "<<i<<" value : ";
        cin>>num;   
        root=insertNode(root,num);              //inserting the data into the tree
    }


    boundaryTraversal(root,res);
    //Printing the Boundary Nodes of the Binary Tree
    if(res.size())
    {
        cout<<"Boundary Traversal : ";
        for(auto x : res)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else
        cout<<"\nThe Binary Node is Empty"<<endl;

    res.clear();

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
