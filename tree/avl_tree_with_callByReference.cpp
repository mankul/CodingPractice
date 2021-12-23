#include<iostream>

#define ROOT_NODES 30

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
	if (root == NULL){
		return 0;
	}
	return root->height;
}

void right_rotation( node * & root){
	node * temp = root->left;
	
	root->left = temp->right;
	temp->right = root;


	root->height = max(get_height(root->left), get_height(root->right));
	temp->height = max(get_height(temp->left), get_height(temp->right));
	root = temp;
}

void left_rotation( node * & root){
	node * temp = root->right;

	root->right = temp->left;
	temp->left = root;
	
	root->height = 1 + max(get_height(root->left), get_height(root->right));
	temp->height = 1 + max(get_height(temp->left), get_height(temp->right));
	root = temp;
	
}


void balance_tree(node *  & root, node * node_pointer){
	int balance = max(get_height(root->left), get_height(root->right));
	if(balance > 1){
		if(root->left->value < node_pointer->value)
			left_rotation(root->left);
		right_rotation(root);
	}
	else if(balance < -1){
		if(root->right->value > node_pointer->value)
			right_rotation(root->right);
		left_rotation(root);
	}
}



void insert_into_tree(node * & root, node * node_pointer){
	if ( root == NULL){
		root = node_pointer;
		return;
	}
	if ( root->value > node_pointer->value){
		if(root->left == NULL)
			root->left = node_pointer;
		else	
			insert_into_tree(root->left, node_pointer);
	}
	else{
		if(root->right == NULL)
			root->right = node_pointer;
		else	
			insert_into_tree(root->right, node_pointer);
	}

	root->height = 1 + max( get_height(root->left), get_height(root->right));

}

void inorder_traversal( node * root){

	if(root == NULL)
		return;
	inorder_traversal(root->left);
	cout<<root->value<<"\t"<<root->height<<endl;
	inorder_traversal(root->right);
}



int main(){

	node *root, * node_pointer;
	int nodeValue;
	cout<<"Please enter the nodes one by one"<<endl;
	for(int i = 0; i< ROOT_NODES; i++){
		cin>>nodeValue;
		node_pointer = new node(nodeValue);
		if(root == NULL){
			cout<<"Root Node is null"<<endl;
		}
		insert_into_tree(root, node_pointer);
		cout<<"Inorder Traversal so far is "<<endl;
		inorder_traversal(root);
		cout<<"\n"<<endl;
	}
	return 0;
}


