#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Top View of the Binary Tree,
    Top View of the Binary Tree is the nodes that are visible from the top view of the Tree (The Left Most & Right Most Nodes of the Tree)

    TIME COMPLEXITY  : O(N) for traversing N number of nodes,
    SPACE COMPLEXITY : O(N) for storing nodes in one queue and their corresponding index in other queue
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

void printTopViewofBinaryTree(struct BinaryNode* root)
{
    if(root == nullptr)
        return; 
    queue<BinaryNode*> node_queue;                          //queue for storing nodes in level order
    queue<int> node_index;                                  //queue for corresponding index of the nodes
    
    node_queue.push(root);                                  //push root node and corresponding index as 0 initially to both the queues respectively
    node_index.push(0);
    int leftBoundaryIndex = 0, rightBoundaryIndex = 0;          //initializing the left and right boundary index

    while(!node_queue.empty())                                 //executes while the queue is not empty
    {
        int currentNodeIndex = node_index.front();              //fetching current front node and index from the queue
        BinaryNode* currentNode = node_queue.front();
        if( currentNodeIndex <= leftBoundaryIndex || currentNodeIndex >= rightBoundaryIndex )               // if the current index of the node matches any valid boundary value
        {
            cout<<currentNode->data <<" ";                  //printing the value of the current node

            if(currentNodeIndex <= leftBoundaryIndex)       //if node is the current leftmost node
                --leftBoundaryIndex;
            if(currentNodeIndex >= rightBoundaryIndex)      //if node is the current rightmost node
                ++rightBoundaryIndex;
        }

        if(currentNode->leftNode)
        {
            node_queue.push(currentNode->leftNode);        //push the left child and it's index as currentIndex - 1 to the respective queues
            node_index.push(currentNodeIndex-1);
        }
        if(currentNode->rightNode)
        {
            node_queue.push(currentNode->rightNode);      //push the right child and it's index as currentIndex + 1 to the respective queues
            node_index.push(currentNodeIndex + 1);
        }

        node_queue.pop();                           //popping the front nodes which are recently visited
        node_index.pop();

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

    printTopViewofBinaryTree(root);             //calling the function to print the Top View of the Binary Tree

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
