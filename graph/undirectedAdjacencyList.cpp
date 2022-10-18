#include<iostream>
#include<vector>



void insertToGraph(std::vector<int> (& adj)[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	int nodes;
	std::cin>>nodes;
	std::vector<int> adj[nodes];

	int edges;
	std::cin>>edges;
	int u, v;
	for(int i = 0; i < edges; i++){
		std::cin>>u>>v;
		insertToGraph(adj, u, v);
	}


	for(int i = 0; i < nodes; i++){
		for(auto iterator: adj[i]){
			std::cout<<i<<" -- "<<iterator<<"\t";
		}
		std::cout<<std::endl;
	}

	return 0;
}
