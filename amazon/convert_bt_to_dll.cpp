#include<iostream>
#include<stack>

using namespace std;


// DLL is a doubly linked list.
// Convert this binary tree into inplace DLL

// Given BT 
//                       A
//                 B          C
//             D      E    F       G

// Expected DLL inplace is
//         D = B = E = A = F = C = B


// head at left most element of Binary tree




struct Node{
    Node *left;
    Node * right;
    int val;
};



typedef struct Node node;


void insertIntoTree(node * head, node * nodeToInsert){
    if(head->val > nodeToInsert->val){
        if(head->left == NULL)
            head->left = nodeToInsert;
        else
            insertIntoTree(head->left, nodeToInsert);
    }
    else{
        if(head->right == NULL)
            head->right = nodeToInsert;
        else
            insertIntoTree(head->right, nodeToInsert);
    }
}


void displayInOrder(node * head){
    if(head  == NULL)
        return;

    displayInOrder(head->left);
    cout<<head->val<<" ";
    displayInOrder(head->right);
}

node * inputTree(node *  head){
    int n;
    cin>>n;
    int val;
    for(int i = 0; i < n; i++){
        cin>>val;
        node * newNode = new node();
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        if(head == NULL){
            head = newNode;
        }
        else{
            insertIntoTree(head, newNode);
        }
    }
    return head;
}


// node * convert(node * head){
//     if(head == NULL)
//         return NULL;
//     convert(node->left);

// }

node * convertToDLL(node * head){
    node * headDLL;
    node * pointer = head;
    stack<node *> pointer_stack;
    while(pointer->left != NULL){
        pointer_stack.push(pointer);
        pointer = pointer->left;
    }
    pointer = pointer_stack.top();
    headDLL = pointer;
    pointer_stack.pop();    
    node * dllPointer;
    dllPointer = headDLL;
    if(pointer->right != NULL)
        pointer_stack.push(pointer->right);
    while(!pointer_stack.empty()){
        pointer = pointer_stack.top();
        dllPointer->right = pointer;
        pointer->left = dllPointer;
        dllPointer = dllPointer->right;
        if(pointer->right != NULL)
            pointer_stack.push(pointer->right);
    }



    return headDLL;
}

int main(){

    // if the tree is present in Links


    // initialize a tree first

    node * head;
    head = inputTree(head);
    
    displayInOrder(head);

    cout<<endl;
    
    // let us create a tree . For our example input a increasing order value tree.


    // convert it to DLL,

    head = convertToDLL(head);



    return 0;
}