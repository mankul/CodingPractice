
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

struct node{

	node * left;
	node * right;
	int value;

	node()
	{
		left = NULL;
		right = NULL;
		value = -1;

	}
};

int find_element(vector<int> inorder_traversal, int value)
{
	int index;
	int size = inorder_traversal.size();
	for(int i = 0; i < size; i++)
	{
		if( inorder_traversal[i] == value)
		{	
			index = i;
			break;
		}
		return index;
	}
}


void create_binary_search_tree(stack<node *> & S, node * current_node, vector<int> inorder_traversal)
{
	if(S.empty())
	{
		S.push(current_node);
		return;
	}
	node * tos = S.top();
	int index1 = find_element(inorder_traversal, tos->value);
	int index2 = find_element(inorder_traversal, current_node->value);
	if (index2 < index1)
	{
		tos->left = current_node;
		
	}	
	else
	{
		//`if(!S.empty())
		node * temp_node = S.top();
		S.pop();

		if(S.empty())
		{
			temp_node->right = current_node;
		}
		S.push(current_node);
		create_binary_search_tree(S, current_node, inorder_traversal);
	}

}

void create_binary_search_tree(vector<int> & preorder_traversal, vector<int> & inorder_traversal, int num_nodes)
{

	stack<node *> S;

	int value  = preorder_traversal[0];
	node * root_node = new node();
	root_node->value = value;
	cout<<root_node->value;
	S.push(root_node);
	for(auto elem = 1; elem != num_nodes; elem++)
	{
		node * current_node = new node();
		current_node->value = preorder_traversal[elem];
		create_binary_search_tree(S,current_node,inorder_traversal);
	}
}



int main()
{


	int num_nodes;
	
	cout<<"enter total number of elements"<<endl;
	cin>>num_nodes;
	
	vector<int> preorder_traversal(num_nodes), postorder_traversal(num_nodes), inorder_traversal(num_nodes);
	cout<<"enter preorder traversal"<<endl;
	for(auto i = 0; i< num_nodes; i++)
	{
		cin>>preorder_traversal[i];
	}

	cout<<"enter inorder traversal"<<endl;
	for(auto i = 0; i< num_nodes; i++)
	{
		cin>>inorder_traversal[i];
	}


	// create a binary search tree
	//
	
	create_binary_search_tree(preorder_traversal, inorder_traversal, num_nodes);



	return 0;
}
