#include<iostream>
#include"tree_node.h"
#define MAX_NODE 30

using namespace std;

treeNode * make_tree(){
    treeNode * root;
    treeNode * nodePointer;
    for(int i = 0; i< MAX_NODE; i++){
        nodePointer = new treeNode(i);
        root = insert_into_binary_search_tree(root, nodePointer);
    }
}


int main(){

    treeNode * root, * nodePointer;

    root = make_tree();

    return 0;

}