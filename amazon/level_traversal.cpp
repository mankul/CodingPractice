#include<iostream>
#include<queue>
#include<map>
using namespace std;

struct TreeNode{
    struct TreeNode * leftChild;
    struct TreeNode * rightChild;
    int val;
};

typedef struct TreeNode node;



void insertNode(node * & root, int number){
    if(root == NULL){
        root = new node();
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


node * insertIntoTree() // make a binary search tree
{
    node * root= NULL;
    int number;
    int numberOfNodes;
    cin>> numberOfNodes;
    for(int i = 0; i < numberOfNodes; i++){
        cin>>number;
        insertNode(root, number);
    }
    return root;
}


void levelTraversal(node * root){
    queue<node *> nodeQueue;
    map<node *, int> nodeLevel;
    if(root == NULL)
        return;
    nodeQueue.push(root);
    nodeLevel[root] = 0;

    while(!nodeQueue.empty()){// front == back
        node * n = nodeQueue.front();
        cout<<n->val<<" "<<nodeLevel[n]<<endl;
        nodeQueue.pop();
        if(n->leftChild != NULL){
            nodeQueue.push(n->leftChild);
            nodeLevel[n->leftChild] = nodeLevel[n] + 1;
        }
        if(n->rightChild != NULL){
            nodeQueue.push(n->rightChild);
            nodeLevel[n->rightChild] = nodeLevel[n] + 1;
        }
    }
    
}


int main(){


    node * root = insertIntoTree();

    levelTraversal(root);



    return 0;
}