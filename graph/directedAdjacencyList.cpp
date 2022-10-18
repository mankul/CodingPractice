#include<iostream>
#include<vector>




void insertEdgeToGraph(std::vector<int> adj[], int u, int v){
	adj[u].push_back(v);
}


void printGraph(std::vector<int> adj[], int nodes){

	for(int i = 0; i < nodes; i++){
		std::cout<<i<<"->";
		for(auto iterator: adj[i]){
			std::cout<<iterator<<"\t";
		}
		std::cout<<std::endl;

	}


}


int main(){


	int nodes;
	std::cin>>nodes;
	std::vector<int> adj[nodes];
	
	int edges;
	int u, v;
	std::cin>>edges;
	for(int i = 0; i < nodes; i++){
		std::cin>>u>>v;
		insertEdgeToGraph(adj,u ,v); 
	}

	printGraph(adj, nodes);



	return 0;
}
