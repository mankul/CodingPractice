#include"../treeTemplate.hpp"
#include<iostream>

using namespace BST;




int main(){

    BST::bstNode * root;
    int numberOfNodes;
    int nodeValue;
    std::cin>>numberOfNodes;
    std::cin>>nodeValue;
    root  = BST::createNode(nodeValue);
    for(int i = 1 ; i < numberOfNodes ; i++)
    {
        std::cin>>nodeValue;
        BST::addNodeToTree(nodeValue, root);
    }
    BST::displayInorderWithLevel(root, 0);

    int pos=0,k;
    std::cin>>k;
    BST::displayKthLargest(root,pos,k);
    
    // kth largest
}
