#include "redBlackNode.hpp"
#include<iostream>
using namespace std;



int main(){

    cout<<"enter number of nodes, then enter numbers to insert into RB tree"<<endl;

    int n, num;
    cin>>n;
    RedBlackNode * root;
    for(int i = 0; i< n; i++){
        cin>>num;
        root = insert(num, root);
    }
    displayTree(root);

    return 0;
}