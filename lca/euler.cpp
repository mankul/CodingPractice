#include<iostream>
#include<vector>
#include<map>


using namespace std;

struct graph_node;

struct nextNodesArray
{
	vector<graph_node *> outgress;
};



struct graph_node{
	int nodeNumber;
	nextNodesArray nextNodes;
};


int main(){
	cout<<"enter number of nodes in DAG"<<endl;
	int n, nodeNum;
	cin>>n;
	cout<<"for "<< n<<" number of lines, node numbers from 0, enter target nodes seperated by white space"<<endl;


	map<int, graph_node *> dictionary;

	for(int i = 1; i < n; i++)
	{
		graph_node * rootNode = new graph_node();

		
	}
	return 0;
}
