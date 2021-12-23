
#include<iostream>
#define LEVEL 100


struct node{
	int value;
	node * left;
	node * right;
	node()
	{
	left=NULL;
	right=NULL;
	}
	node(int value_){
	//node();
	left = NULL;
	right = NULL;
	value = value_;
	}


};



using namespace std;


void insert_node_to_left(node * root, node * newNode){
	root->left = newNode;
}

void insert_node_to_right(node * root, node * newNode){
	root->right = newNode;
}

void find_place( node * root, node * newNode){
	cout<<"find place "<<root->value<<endl;
	if (root->value > newNode->value){
		if (root->left == NULL)
			root->left  = newNode;
		else{	
			cout<<"searching in left subtree"<<endl;
			find_place(root->left, newNode);
		}
	}

	else{
		if (root->right == NULL)
			root->right = newNode;	
		else	{
			cout<<"traversing right subtree"<<endl;
			find_place(root->right, newNode);
		}
	}
	
}





void inorder_traversal(node * root){


	if(root == NULL)
		return;

	inorder_traversal(root->left);
	cout<<root->value<<"\t";
	inorder_traversal(root->right);
}



void postorder_traversal(node * root){
	if(root  == NULL)
		return;
	postorder_traversal(root->left);
	postorder_traversal(root->right);
	cout<<root->value<<"\t";

}
void preorder_traversal(node * root){
	if(root  == NULL)
		return;
	cout<<root->value<<"\t";
	preorder_traversal(root->left);
	preorder_traversal(root->right);

}



int main(){
	cout<<"binary tree"<<endl;
	node  newNode;
	node * node_pointer;
	node * root;
	for(int i = 0 ; i< LEVEL; i ++){
		//newNode =  node(i);
		node_pointer = new node(i);
		cout<<"node pointer address is "<<node_pointer<<endl;
		if(root == NULL)
			{
			cout<<"root is null"<<endl;
			root = node_pointer;
			}
		else
			find_place(root, node_pointer);
		if(root->left== NULL)
			cout<<"left subtree is null while inserting node "<<node_pointer->value<<endl;
		if(root->right== NULL)
			cout<<"right subtree is null while inserting node "<<node_pointer->value<<endl;
	}
	if(node_pointer -> left == NULL)
		cout<<node_pointer->value<<"some error"<<endl;
	cout<<"inorder traversal"<<endl;
	inorder_traversal(root);
	cout<<"\n\npreorder traversal"<<endl;
	preorder_traversal(root);
	cout<<"\n\npreorder traversal"<<endl;
	postorder_traversal(root);
}
