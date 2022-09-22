#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;

typedef struct Node{
    struct Node * leftNode;
    struct Node * rightNode;
    int val;
} treeNode;


treeNode * createNewNode(int value){
        treeNode * node = new treeNode();
        node->val = value;
        node->leftNode = nullptr;
        node->rightNode = nullptr;
        return node;
}

// inserting in order
void insertIntoTree(treeNode *  &root, int value){
    if(root == nullptr){
        root =  createNewNode(value);
        // return root;
    }
    if(root->val > value && root->leftNode == nullptr){
        root->leftNode = createNewNode(value);
    }
    else if(root->val > value ){
        // root->leftNode = 
        insertIntoTree(root->leftNode, value);
    }
    else if(root->val <= value && root->rightNode == nullptr){
        root->rightNode = createNewNode(value);
    }
    else{
        // root->rightNode = 
        insertIntoTree(root->rightNode, value);
    }
    // return root;

}

// depth first search traversal .. iterative
void dfs(stack<treeNode *> stk, vector<int> & traversal){
    while(!stk.empty()){
        treeNode * node = stk.top();
        stk.pop();
        traversal.push_back(node->val);
        if(node->rightNode != nullptr)
            stk.push(node->rightNode);
        if(node->leftNode != nullptr)
            stk.push(node->leftNode);
        // bfs(stk, traversal);
    }

}

void dfs_recursion(treeNode * node, vector<int> & traversal){
    if(node == nullptr)
        return;
    traversal.push_back(node->val);
    dfs_recursion(node->leftNode, traversal);
    dfs_recursion(node->rightNode, traversal);
}


// breadth first search .. iterative
void bfs(queue<treeNode *> q, vector<int> & traversal){
    while(!q.empty()){
        treeNode * node = q.front();
        q.pop();
        traversal.push_back(node->val);
        if(node->leftNode != nullptr)
            q.push(node->leftNode);
        if(node->rightNode != nullptr)
            q.push(node->rightNode);
    }
}


//  recursion used for looping
void bfs_recursion(queue<treeNode *>q, vector<int> & traversal){
    
    if(q.empty())
        return;
    treeNode * node  = q.front();
    q.pop();
    traversal.push_back(node->val);

    if(node->leftNode != nullptr)
        q.push(node->leftNode);
    if(node->rightNode != nullptr)
        q.push(node->rightNode);
    bfs_recursion(q, traversal);
    
}


// iterative approach inorder traversal.
void inOrderTraversal_iterative_links_unaffected(stack<treeNode *> node_stack , vector<int> traversal){
    stack<treeNode *> traversedNodes; // nodes to memorize the inorder node covered so far.
    while(!node_stack.empty()){
        treeNode * node =  node_stack.top();
        node_stack.pop();

        if(!traversedNodes.empty()){
            if( node == traversedNodes.top()){
                traversal.push_back(node->val);
                traversedNodes.pop();
            }
        }
        else{
            traversedNodes.push(node);
            node_stack.push(node);
            

            if(node->rightNode != nullptr)
                node_stack.push(node->rightNode);


            if(node->leftNode != nullptr)
                node_stack.push(node->leftNode);
        }
        
    }
}

void inorserTraversal_links_changed(stack<treeNode *> node_stack, vector<int> traversal){
    while(!node_stack.empty()){
        treeNode * node = node_stack.top();
        node_stack.pop();


        if(node->leftNode == nullptr && node->rightNode == nullptr)
            traversal.push_back(node->val);
        
        else{

            if(node->rightNode!= nullptr)
                node_stack.push(node->rightNode);
            
            node->rightNode = nullptr;

            if(node->leftNode != nullptr){
                treeNode * leftNode = node->leftNode;
                node->leftNode = nullptr;
                node_stack.push(node);
                node_stack.push(leftNode);
            }
            else{
                node_stack.push(node);
            }
        }
    }
}




void inorderTraversal_recursion(treeNode * root, vector<int> & traversal){
    if(root == nullptr)
        return;
    inorderTraversal_recursion(root->leftNode, traversal);
    traversal.push_back(root->val);
    inorderTraversal_recursion(root->rightNode, traversal);
}


void preorderTraversal_iterative(stack<treeNode *> node_stack, vector<int> & traversal){
    while (!node_stack.empty()){
        treeNode * node = node_stack.top();
        node_stack.pop();

        traversal.push_back(node->val);
        if(node->rightNode != nullptr)
            node_stack.push(node->rightNode);
        if(node->leftNode != nullptr)
            node_stack.push(node->leftNode);
    }
    
}


void preorderTraversal_recursion(treeNode * root, vector<int> & traversal){
    if(root == nullptr)
        return;
    traversal.push_back(root->val);
    preorderTraversal_recursion(root->leftNode, traversal);
    preorderTraversal_recursion(root->rightNode, traversal);
} 



void postorderTraversal_iterative(stack<treeNode *> node_stack, vector<int> & traversal){
    while (!node_stack.empty())
    {
        treeNode * node = node_stack.top();
        node_stack.pop();


        if(node->leftNode == nullptr && node->rightNode == nullptr){
            traversal.push_back(node->val);
        }

        else{
            treeNode * leftNode = node->leftNode;
            treeNode * rightNode = node->rightNode;

            node->leftNode = nullptr;
            node->rightNode = nullptr;

            node_stack.push(node);
            if(rightNode != nullptr)
                node_stack.push(rightNode);
            if(leftNode != nullptr)
                node_stack.push(leftNode);
        }
    }

}


void postorderTraversal_recursion(treeNode * root, vector<int> & traversal){
    if(root == nullptr)
        return;
    postorderTraversal_recursion(root->leftNode, traversal);
    postorderTraversal_recursion(root->rightNode, traversal);
    traversal.push_back(root->val);
}





void printTraversal(vector<int> traversal){
    for(auto iterator: traversal){
        cout<<iterator<<endl;
    }
}




int main(){


    treeNode * root = nullptr;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        insertIntoTree(root, i);
    }
    vector<int> traversal;
    stack<treeNode *> nodeStack;
    nodeStack.push(root); 
    bfs(nodeStack, traversal);
    for(auto iter: traversal)
        cout<<iter<<endl;


}