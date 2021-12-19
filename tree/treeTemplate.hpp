#ifndef tree
#include <iostream>
#endif
namespace BST{
	struct bstNode{
		bstNode * left=NULL;
		bstNode * right=NULL;
		int value;
		std::string nameValue="";
		bstNode(int val){
			value = val;
		}
	};

	bstNode * createNode(int nodeValue){
		bstNode * node = new bstNode(nodeValue);
		return node;
	}

	void addNodeToTree(int nodeValue, bstNode * root){
		if (root->value > nodeValue)
			if(root->left != NULL)
				addNodeToTree(nodeValue, root->left);
			else
				root->left = createNode(nodeValue);
		else 
			if(root->right != NULL)
				addNodeToTree(nodeValue, root->right);
			else
				root->right = createNode(nodeValue);
		
	}

	void displayInorder(bstNode * root){
		// l r rt
		if(root->left != NULL)
			displayInorder(root->left);
		std::cout<<root->value;
		if(root->right != NULL)
			displayInorder(root->right);
	}

	void displayInorderWithLevel(bstNode * root, int level){
		// l r rt
		if(root->left != NULL)
			displayInorderWithLevel(root->left, level + 1);
		std::cout<<root->value<<" "<<level<<std::endl;
		if(root->right != NULL)
			displayInorderWithLevel(root->right, level + 1);
	}

	void displayKthLargest(bstNode * root, int & pos, int k){
		//l r rt
		if(root->right == NULL)
			if(pos < k){
				if(root->left != NULL)
				{	pos+=1;
					displayKthLargest(root->left, pos, k);
				}
			else if(pos == k)
			{
				std::cout<<root->value<<std::endl;
				return;
			}
			else
			{
				std::cout<<"not found"<<std::endl;
				return;
			}
		else
			displayKthLargest(root->right, pos, k);
		if(pos == k)
		{
			std::cout<<root->value<<std::endl;
			return;
		}
		else if (pos < k){
			pos+=1;
			displayKthLargest(root->left, pos, k);
		}
			
	}
}
