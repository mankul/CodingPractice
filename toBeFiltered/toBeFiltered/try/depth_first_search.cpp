


#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;


/// tree node
struct node
{

	int node_name;
	vector<node *> adjacent_nodes;



};


void bfs(node * visiting_node, int * graph_visit, queue<node *> & Q)
{
	if(!graph_visit[visiting_node->node_name])
	{
		graph_visit[visiting_node->node_name] = 1;
		cout<<visiting_node->node_name<<endl;
		for( auto iterator = visiting_node->adjacent_nodes.begin(); iterator!= visiting_node->adjacent_nodes.end(); iterator++)
		{
			if(!graph_visit[(*iterator)->node_name])
				Q.push(*iterator);
		}
		while(!Q.empty())
		{
			node * visit_node = Q.front();
			Q.pop();
			if(!graph_visit[visit_node->node_name])
				bfs(visit_node, graph_visit, Q);

		}
	}
}


void breadth_first_search(vector< node *> graph_nodes, int num)
{
	queue<node *> Q;
	int graph_visit[num];
	for(int i = 0; i < num; i++)
		graph_visit[i] = 0;
	for( int i = 0; i<num; i++)
	{
		if(graph_visit[i] == 0)
			bfs(graph_nodes[i], graph_visit, Q);

	}
}



void dfs( node * node1, vector<int> & graph_visit, stack<node *> & S)
{
	if( graph_visit[node1->node_name] == 0)
	{
		graph_visit[node1->node_name] = 1;
		cout<<node1->node_name<<endl;
		if( !node1->adjacent_nodes.empty())
		{
			for( auto iterator  = node1->adjacent_nodes.begin(); iterator != node1->adjacent_nodes.end(); iterator++)
			{
				if(!graph_visit[(*iterator)->node_name])
					S.push(*iterator);
			}
		}
		while(!S.empty())
		{
			node * visit_node = S.top();
			S.pop();
			if(!graph_visit[visit_node->node_name])
				dfs(visit_node, graph_visit, S);
			
		}

	}
}

void depth_first_search( vector<node *> graph_nodes, int num)
{

	stack<node *> S;
vector<int> graph_visit(num);
for(int i = 0; i < num; i++)
{
	graph_visit[i] = 0;
}

for( int i = 0; i < num; i++)
{
	dfs(graph_nodes[i], graph_visit,S);
}
}




int main()

{



	int nodes;
	cin>>nodes;

	int edges;
	cin>>edges;
	int node1, node2;
	node * node_ptr;
	vector<node *> graph_nodes(nodes);
	for( int i = 0 ; i < nodes; i++)
	{
		graph_nodes[i] = NULL;
	}
	for(int i = 0; i < edges; i++)
	{
		cin>>node1>>node2;
		if( graph_nodes[node1] == NULL)
		{

			node_ptr = new node();
			node_ptr ->node_name = node1;
			graph_nodes[node1] = node_ptr;
		}

		if( graph_nodes[node2] == NULL)
		{

			node_ptr = new node();
			node_ptr ->node_name = node2;
			graph_nodes[node2] = node_ptr;
		}

		graph_nodes[node1] -> adjacent_nodes.push_back(graph_nodes[node2]);
		graph_nodes[node2] -> adjacent_nodes.push_back(graph_nodes[node1]);


	}

	for( int i = 0 ; i < nodes; i++)
	{
		cout<<graph_nodes[i]->node_name<<endl;
		for( auto iterator = graph_nodes[i]->adjacent_nodes.begin(); iterator != graph_nodes[i]->adjacent_nodes.end(); iterator++)
		{
			cout<<(*iterator)->node_name<<"\t";
		}
		cout<<"\n\n";
	}
	cout<<"DFS"<<endl;
	depth_first_search(graph_nodes, nodes);

	cout<<"BFS"<<endl;
	breadth_first_search(graph_nodes, nodes);
	return 0;

}
