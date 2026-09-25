#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to print the Bottom View of the Binary Tree,
    Bottom View = Nodes that are visibile when a Binary Tree is seen from the Bottom view.
    Each Left Child has it's line or index as index-1 and
    Right child has it's index as index+1


    TIME COMPLEXITY  : O(N) for traversing N number of nodes by Breadth First Traversal ,
    SPACE COMPLEXITY : O(K) where K = number of Bottom view nodes
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

void printBottomView_Tree(struct BinaryNode* root)          //function to print the bottom view nodes of the Binary Nodes
{
    if(root == nullptr)             //if tree is empty
        return;

    queue<pair<int,struct BinaryNode*>> q;                  //queue for storing pair of <index , Node*.
    map<int,struct BinaryNode*> bottomViewMap;              //Ordered Map to store latest nodes of each vertices of the tree

    q.push({0,root});                 //push root node with index=0 initially
    while(!q.empty())
    {
        int index = q.front().first;                            //fetching index of front element in queue
        struct BinaryNode* currentNode = q.front().second;      //fetching front node in the queue
        q.pop();                                                //pop the current front element 

        bottomViewMap[index] = currentNode;         //add or update the vertices with latest node
        if(currentNode->leftNode)
            q.push({index-1,currentNode->leftNode});            //push left node with index - 1 as pair<>
        if(currentNode->rightNode)
            q.push({index+1,currentNode->rightNode});           //push right node with index + 1 as pair<>

    }

    cout<<"Bottom View Nodes : ";
    for(auto a : bottomViewMap)                 //print the bottom view nodes from traversing the keys(vertices) in the ordered map
    {
        cout<<a.second->data<<" ";
    }
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

    printBottomView_Tree(root);

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
