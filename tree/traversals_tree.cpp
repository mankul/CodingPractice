#pragma once
#include<iostream>
#include"tree_node.h"


treeNode::treeNode(int value_){
    value = value_;
    height = 1;
}


void inorder_traversal(treeNode * root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    std::cout<<root->value<<std::endl;
    inorder_traversal(root->right);
}


void preorder_traversal(treeNode * root){
    if(root == NULL){
        return;
    }
    std::cout<<root->value<<std::endl;
    inorder_traversal(root->left);
    inorder_traversal(root->right);
}


void postorder_traversal(treeNode * root){
    if(root == NULL){
        return;
    }
    inorder_traversal(root->left);
    inorder_traversal(root->right);
    std::cout<<root->value<<std::endl;

}


