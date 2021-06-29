#include<iostream>

using namespace std;


struct node {
    int value;
    int height;
    node * left;
    node * right;
    node(){
        left = NULL;
        right = NULL;
    }
    node(int value_){
        height = 1;
        value = value_;
        node();
    }

};

int get_height(node * root){
    if (root == NULL)
        return 0;
    return root->height;
}

node * left_rotation(node * root){
    node * temp = root->right;
    root->right = temp->left;
    temp->left = root;


    root->height = 1 + max(get_height(root->left), get_height(root->right));
    temp->height = 1 + max(get_height(temp->left), get_height(temp->right));
    return temp;
}

node * right_rotation(node * root){
    node * temp = root->left;
    root->left = temp->right;
    temp->right = root;


    root->height = 1 + max(get_height(root->left), get_height(root->right));
    temp->height = 1 + max(get_height(temp->left), get_height(temp->right));
    return temp;
}

node * balance_tree(node * root, node * node_pointer){

    int balance = get_height(root->left) - get_height(root->right);
    if(balance > 1){
        // left side disbalance
        if(node_pointer->value > (root->left)->value)
            root->left = left_rotation(root->left);
        root = right_rotation(root);

    }
    else if(balance < -1){
        // node is inserted to the right side
        if(node_pointer->value < (root->right)->value)
            root->right = right_rotation(root->right);
        root = left_rotation(root);
    }
    return root;

}

// insert to binary search tree.
node * insert_to_binary_search_tree(node * root, node * node_pointer){
    if(root == NULL){
        cout<<"Root inserted"<<endl;
        root = node_pointer;
        return root;
    }
    if (root->value > node_pointer->value){
        if (root->left == NULL)
            root->left = node_pointer;
        else
            root->left = insert_to_binary_search_tree(root->left, node_pointer);
    }
    else{
        if(root->right == NULL)
            root->right = node_pointer;
        else
            root->right = insert_to_binary_search_tree(root->right, node_pointer);

    }


    root = balance_tree(root, node_pointer);

    root->height = 1 + max( get_height(root->left), get_height(root->right));
    return root;   
}

void inorder_traversal(node * root){
    if(root == NULL)
        return;
    inorder_traversal(root->left);
    cout<<root->value<<"\t"<<root->height<<endl;
    inorder_traversal(root->right);
}


int main(){
    node * node_pointer;
    node * root;

    root = new node(0);
    for(int i = 1; i< 10; i++){
        node_pointer = new node(i);
        // cout<<node_pointer<<" "<<node_pointer->value<<endl;
        root = insert_to_binary_search_tree(root, node_pointer);
    }

    inorder_traversal(root);

    return 0;
}