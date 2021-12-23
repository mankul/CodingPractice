#include<iostream>
#include<vector>
#include<queue>

using namespace std;



struct node {
	node * left=NULL ;
	node * right = NULL;
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
			root_node->right = new_node;
		}
	}
}



void display( node *);
void display( node *, int);

node * constructTreeUtil( vector<int> preorder_traversal,  int num_nodes)
{
	node * root_node = new node();
	for (auto node_index = 0; node_index < num_nodes; node_index++)
	{
		if (root_node->node_value == -1)
		{
			root_node->node_value = preorder_traversal[node_index];
			continue;
		}
		node * new_node = new node();
		new_node->node_value = preorder_traversal[node_index];
		
		findPlaceAndReplace(root_node, new_node);
	}
	cout<<"BFS"<<endl;

	//display(root_node);
	int level = 0;
	display(root_node, level);
	return root_node;
}






void display(node * root_node, int level)
{

	
	queue<pair<node *, int>> Q;
	
	Q.push(make_pair(root_node,level));
	cout<<root_node->node_value<<endl;
	level++;
	//return;
	
	while(!Q.empty())
	{
		
		auto newPair = Q.front();
		node * pointer_node = newPair.first;
		cout<<pointer_node->node_value<<" "<<newPair.second<<endl;
		if(pointer_node->left != NULL)
		{
			newPair = make_pair(pointer_node->left,level);
			Q.push(newPair);
		}

		if(pointer_node->right != NULL)
		{
			newPair = make_pair(pointer_node->right, level);		
			Q.push(newPair);
		}
		Q.pop();
		level++;
	}
	
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
		cout<<pointer_node->node_value<<endl;
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
