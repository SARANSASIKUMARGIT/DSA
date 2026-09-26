#include<bits/stdc++.h>
using namespace std;

                    /*      Saran SK       */

/*
    C++ Program to find whether the Binary Tree is Symmetric or Not ?
    A symmetric tree is a binary tree whose left and right subtrees are mirror images of each other, 
    meaning each node’s left child matches the corresponding node’s right child in value and structure.


    TIME COMPLEXITY  : O(N) for recursively traversing N/2 times,
    SPACE COMPLEXITY : O(h) due to recursion stack , h = height of the tree
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

bool isSymmetricTree(struct BinaryNode* node1,struct BinaryNode* node2)             //function to verify whether the tree is symmetric or not
{
    if(node1 == nullptr && node2 == nullptr)                    //if both nodes are null nodes
        return true;
    if(node1 == nullptr || node2 == nullptr)                    //if any one of the node is null and other is not a null node
        return false;
    if(node1->data == node2->data)          //if both nodes are equal , check the further left and right child nodes
        return ( isSymmetricTree(node1->leftNode,node2->rightNode) && isSymmetricTree(node1->rightNode,node2->leftNode));

    return false;           //if both nodes are not equal , return false
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

    if(isSymmetricTree(root->leftNode,root->rightNode))     //calling function to verify whether the tree is symmetric 
        cout<<"\nThe Tree is Symmetric"<<endl;
    else
        cout<<"\nThe Tree is not Symmetric"<<endl;

    deleteTree(root);                                         //deallocating the memory of all nodes of the return


    return 0;
}
