#include<iostream>
#include<vector>
#include<queue>

using namespace std;



struct node {
	node * left=NULL ;
	node * right = NULL;
	int level = -1;
	int node_value = -1;

};


void  findPlaceAndReplace(node * root_node, node * new_node)
{
	//cout<<root_node->node_value<<"rrr"<<endl;
	if(root_node == NULL)
	{
		root_node = new_node;

	}
	else if ( root_node->node_value > new_node->node_value)
	{
		if ( root_node->left != NULL)
		{
			findPlaceAndReplace( root_node->left, new_node);
		}
		else
		{
			new_node->level = root_node->level + 1;
			root_node->left = new_node;
			
		}
	}
	else if( root_node->node_value <= new_node->node_value)
	{
		if( root_node->right != NULL)
		{
			findPlaceAndReplace( root_node->right, new_node);
		}		
		else
		{
			new_node->level = root_node->level + 1;
			root_node->right = new_node;
		}
	}
}



void display( node *);

node * constructTreeUtil( vector<int> preorder_traversal,  int num_nodes)
{
	node * root_node = new node();
	for (auto node_index = 0; node_index < num_nodes; node_index++)
	{
		if (root_node->node_value == -1)
		{
			root_node->node_value = preorder_traversal[node_index];
			root_node->level = 0;
			continue;
		}
		node * new_node = new node();
		new_node->node_value = preorder_traversal[node_index];
		
		findPlaceAndReplace(root_node, new_node);
	}
	cout<<"BFS"<<endl;

	display(root_node);
	return root_node;
}
















void display(node * root_node)
{

	int level=0;
	queue<node *> Q;
	Q.push(root_node);
	cout<<root_node->node_value<<endl;
	
	//return;
	
	while(!Q.empty())
	{
		node * pointer_node = Q.front();
		cout<<pointer_node->node_value<<"\t"<<pointer_node->level<<endl;
		if(pointer_node->left != NULL)
			Q.push(pointer_node->left);
		if(pointer_node->right != NULL)
			Q.push(pointer_node->right);
		Q.pop();
	}

}


int main()
{
	int num_nodes = 10;
	int node_value;
	cout<<"enter number of nodes in preorder traversal"<<endl;
	cin>>num_nodes;
	vector<int> preorder_traversal(num_nodes);
	for (auto i = 0; i< num_nodes; i++)
	{
		cin>>node_value;
		preorder_traversal[i] = node_value;
	}

	node * result = constructTreeUtil(  preorder_traversal, num_nodes);
	return 0;
}
