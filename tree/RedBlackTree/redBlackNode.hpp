#ifndef REDBLACK
#define REDBLACK
#include<iostream>

#define BLACK 0
#define RED 1



struct RedBlackNode{
	RedBlackNode * leftNode;
	RedBlackNode * rightNode;
	RedBlackNode * parent;
	int color;
	int value;
	RedBlackNode(int val)
	{
		std::cout<<"Node created with value"<<std::endl;
		value = val;
		color = RED;
		leftNode = NULL;
		rightNode = NULL;
		parent = NULL;
	}

};

RedBlackNode * rightRotation(RedBlackNode * node);
RedBlackNode * leftRotation(RedBlackNode * node);

void insertCase1(RedBlackNode * node);
void insertCase2(RedBlackNode * node);
void insertCase3(RedBlackNode * node);
void insertCase4(RedBlackNode * node);
void insertCase5(RedBlackNode * node);

// printing inorder of the BST
void displayTree(RedBlackNode * root){

	if(root == NULL)
		return;
	displayTree(root->leftNode);
	std::cout<<"node value "<<root->value<<" color "<<root->color<<std::endl;
	displayTree(root->rightNode);
}	

RedBlackNode * grandParent( RedBlackNode * n){
	if(n!= NULL && n->parent != NULL)
		return n->parent->parent;
	else
		return NULL;
}

RedBlackNode * uncle( RedBlackNode * n){
	RedBlackNode * g = grandParent(n);
	if(g != NULL){
		if(n->parent == g->leftNode)
			return g->rightNode;
		if(n->parent == g->rightNode)
			return g->leftNode;
	}
}

void insertToPlace(RedBlackNode * root, RedBlackNode * n){
	if(root->value > n->value)
		if(root->leftNode != NULL)
			insertToPlace(root->leftNode, n);
		else
		{
			root->leftNode = n;
			n->parent = root;
		}
	else
		if(root->rightNode != NULL)
			insertToPlace(root->rightNode, n);
		else{
			root->rightNode = n;
			n->parent = root;
		}
}


RedBlackNode * insert(int val, RedBlackNode * root){
	RedBlackNode * n = new RedBlackNode(val);
	n->color = RED;
	if(root == NULL)
		root = n;
	// if(root != NULL)
	// 	insertToPlace(root, n);
	// 	insertCase1(n);
	return root;
}

void insertCase1(RedBlackNode * n){
	if(n->parent == NULL)// root node
		n->color = BLACK;
	else
		insertCase2(n);
}

void insertCase2(RedBlackNode * n){
	if(n->parent->color == BLACK)
			return;
		else
			insertCase3(n);
}

void insertCase3(RedBlackNode * n){
	// when the parent node is red and uncle node is also red
	if(n->parent != NULL){
		RedBlackNode * u = uncle(n);
		if((n->parent->color == RED && u->color == RED)){
			RedBlackNode * g = grandParent(n);
			if(g->parent != NULL)// not root
			{
				g->color = RED;
				n->parent->color = BLACK;
				u->color = BLACK;
				insertCase1(g);
			}
			else{
				n->parent->color = BLACK;
				u->color = BLACK;
			}
		}
		insertCase4(n);
	}
}
void insertCase4(RedBlackNode * n){
	// when the uncle node is BLACK, but parent node is red, so we first see if we needs to rotate the p node

	// if n is rightchild of p and p is left child of g
	RedBlackNode * u, *g, *p = n->parent;
	
	if(p != NULL ){
		u = uncle(n);
		g = grandParent(n);
		if(p->color == RED)
			if( p == g->leftNode && n == p->rightNode){
				n=leftRotation(p);
				n=n->leftNode;
			}
			else if(p == g->rightNode && n == p->leftNode){
				n=rightRotation(p);
				n = n->rightNode;
			}
		insertCase5(n);
	}
}

void insertCase5(RedBlackNode * n){
	RedBlackNode * g, *p, *r;
	g = grandParent(n);
	p = n->parent;
	if( p == g->leftNode)// LL
	{
		r = rightRotation(g);
		r->rightNode->color = RED;
		r->color = BLACK;
	}
	else{
		r = leftRotation(g);
		r->leftNode->color = RED;
		r->color = BLACK;
	}

}

RedBlackNode * rightRotation(RedBlackNode * n){
	RedBlackNode * ptr, * ptr1, *ptr2;
	ptr = n->parent;
	ptr1 = n->leftNode;
	ptr2 = ptr1->rightNode;
	n->leftNode = ptr2;
	ptr1->rightNode = n;

	if(ptr != NULL){
		if(n == ptr -> rightNode)
			ptr->rightNode = ptr1;
		else
			ptr->leftNode = ptr1;
	}
	return ptr1;
}
RedBlackNode * leftRotation(RedBlackNode * n){
	RedBlackNode * ptr, * ptr1, *ptr2;
	ptr = n->parent;
	ptr1 = n->rightNode;
	ptr2 = ptr1->leftNode;
	n->rightNode = ptr2;
	ptr1->leftNode = n;

	if(ptr != NULL){
		if(n == ptr -> rightNode)
			ptr->rightNode = ptr1;
		else
			ptr->leftNode = ptr1;
	}
	return ptr1;
}

#endif
