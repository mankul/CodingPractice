
#include<iostream>

#include"tree_node.h"

treeNode * insert_into_binary_search_tree(treeNode * root, treeNode * nodePointer){
    if (root == NULL){
        root = nodePointer;
        return root;
    }

    if(root->value > nodePointer->value){
        insert_into_binary_search_tree(root->left, nodePointer);
    }
    else{
        insert_into_binary_search_tree(root->right, nodePointer);
    }

    return root;
    
}

