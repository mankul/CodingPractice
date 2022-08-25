// binary search tree where some order is present in node values


#include<iostream>
#include<stack>
using namespace std;

struct TreeNode{
    struct TreeNode * leftChild;
    struct TreeNode * rightChild;
    int val;
};

typedef struct TreeNode Node;



void insertNode(Node * & root, int number){
    if(root == NULL){
        root = new Node();
        root->val = number;
    }
    else{
        if(root->val > number){
            insertNode(root->leftChild, number);
        }
        else{
            insertNode(root->rightChild, number);
        }
    }
}


Node * insertIntoTree() // make a binary search tree
{
    Node * root= NULL;
    int number;
    int numberOfNodes;
    cin>> numberOfNodes;
    for(int i = 0; i < numberOfNodes; i++){
        cin>>number;
        insertNode(root, number);
    }
    return root;
}


void isBinarySearchTree(Node * root, bool & isBST){
    if(root != NULL)
        return;
    if(root->leftChild != NULL){
        if(root->val < root->leftChild->val){
            isBST = false;
            return;
        }
        isBinarySearchTree(root->leftChild, isBST);
    }
    if(!isBST)
        return;
    if(root->rightChild != NULL){
        if(root->val > root->rightChild->val){
            isBST=false;
            return;
        }
        isBinarySearchTree(root->rightChild, isBST);
    }
}



void isBSTWithoutRecursion(Node * root, bool isBST){
    stack<Node *> nodeStack;
    if(root == NULL){
        cout<<"empty tree"<<endl;
        return;
    }
    nodeStack.push(root);
    while(!nodeStack.empty()){
        Node * pointer = nodeStack.top();
        nodeStack.pop();
        if(pointer->leftChild != NULL){
            if(pointer->leftChild->val > pointer->val){
                isBST = false;
                return;
            }
            nodeStack.push(pointer->leftChild);
        }
        if(pointer->rightChild != NULL){
            if(pointer->rightChild->val < pointer->val){
                isBST = false;
                return;
            }
            nodeStack.push(pointer->rightChild);
        }
    }
}

int main(){

    Node * root;
    root = insertIntoTree();
    bool isBST = true;
    isBinarySearchTree(root, isBST);
    if(isBST)
        cout<<"BINARY SEARCH TREE"<<endl;
    else
        cout<<"Not a BINARY SEARCH TREE"<<endl;
    isBST = true;
    isBSTWithoutRecursion(root, isBST);
    cout<<((isBST)?"BINARY SEARCH TREE":"NOT A BINARY SEARCH TREE")<<endl;
}