


#include<iostream>

#define COUNTSTREAM 20


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
		
		value = value_;
		node();
	}
};



using namespace std;


int get_height(node * root){
	if (root  == NULL)
		return 0;
	return root->height;
}





node *  left_rotate(node * root){
	node * temp = root->right;
	root->right = temp->left;
	temp->left = root;

	root->height = 1 + max(get_height(root->left),get_height(root->right));
	temp->height = 1 + max(get_height(temp->left), get_height(temp->right));

	return temp;	

}


node *  right_rotate( node * root){
	node * temp = root->left;
	root->left = temp->right;
	temp->right = root;
	
	root->height = 1 + max(get_height(root->left), get_height(root->right));
	temp->height = 1 + max(get_height(temp->left), get_height(temp->right));

	return temp;
	
}




void balance_tree( node * root, node * newNode){
	int balance = (root->left)->height - (root->right)->height ;
	
	if( balance > 1){
		if ( newNode->value > root->left->value)
		{
			// node is inserted in right subtree of the left node of root.
			root->left = left_rotate(root->left);
			right_rotate(root);
		}
		else{
			right_rotate(root);
		}
	}
	if ( balance < -1){

		// means right side height is greater.
		if ( newNode->value > root->right->value){
			// means the node is inserted in right subtree of the right node of root. so just give a one left turn to adjust
			left_rotate(root);
		}
		else{
			// means the node is in the left part of the right node of root. so first adjust the right node of root by twisting it 
			// right then left rotate the root node.

			root->right = right_rotate(root->right);
			left_rotate(root);
		}
	}	


	//return root;

}

void  insertion_to_tree(node * root, node * newNode){
	// cout<<"code called"<<newNode->value<<endl;
	if (root == NULL){
		root = newNode;
		return ;
	}	
	if (root->value > newNode->value){
		if (root->left == NULL)
			root->left = newNode;
		else
			insertion_to_tree(root->left, newNode);
	}

	else{
		if (root->right == NULL)
			root->right = newNode;
		else
			insertion_to_tree(root->right, newNode);
	}

	
	//root->height = 1 + max( get_height(root->left),get_height(root->right));
	
}


void inorder_display(node * root)
{
	if(root == NULL)
		return;
	inorder_display(root->left);
	cout<<root->value<<"\t";
	inorder_display(root->right);
}






int main(){

	node * root = NULL;
	node * newNode;
	for(int i = 0; i < COUNTSTREAM; i++)
	{
		newNode = new node(i);
		// // cout<<newNode->value<<newNode<<endl;
		if (root == NULL){
			// cout<<"root null"<<endl;
			root = newNode;
			root->height = 0;
		}
		
		insertion_to_tree(root, newNode);
		cout<<root->value<<endl;
	}

	// inorder_display(root);


}
