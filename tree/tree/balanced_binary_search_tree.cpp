


#include<iostream>
#define NODES 20
using namespace std;


struct node {

	int value;
	node * left;
	node * right;

	node(){
	left = NULL;
	right= NULL;
	}
	node(int value_){
		node();
		value = value_;
	}

};


void find_place(node * root, node * pointer){
	if (root->value > pointer->value)
	{	
		if (root->left != NULL)
			find_place(root->left, pointer);
		else
			root->left = pointer;
	
	}
	else{
		if ( root->right != NULL)
			find_place(root->right, pointer);
		else
			root->right = pointer;
	}
}


void in_order_traversal(node * root){
	if(root == NULL)
		return;
	in_order_traversal(root->left);
	cout<<root->value<<"\t";
	in_order_traversal(root->right);
}


int main(){

	node * node_pointer;
	node * root;
	
	for(int i =0 ; i < NODES; i++){
	node_pointer = new node(i);
	if (root == NULL)
		root = node_pointer;
	else
		find_place(root, node_pointer);

	}

	
	in_order_traversal(root);



	return 0;
}
