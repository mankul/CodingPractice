
#include<iostream>
#include<vector>

using namespace std;

struct node {
	int value;
	node * left;
	node * right;
	node * parent;
	node(int val)
	{
		value = val;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};

void insert_to_min_heap(node * root, int number, node * last_node, int & level, int & column)
{
	if(root == NULL)
	{
		root = new node(number);
		last_node = root;
		level = 1;
		column = 1;
	}
	else
	{
		node * insert_node, ptr = root;
		insert_node = new node(number);
		
		if(last_node->left ==NULL)
			last_node->left = insert_node;
		else if( last_node->right ==NULL)
			last_node->right = insert_node;
		else
		{
			if

		}
				
		
	}
}

void delete_from_min_heap();

int main()
{

	node * root=NULL;
	node * last_node=NULL;

	int max_iterations = 20;

	int number;
	for(int i = 0; i<max_iterations; i++)
	{
		cin>>number;
		insert_to_min_heap(root,number,last_node);

	}

	return 0;
}
