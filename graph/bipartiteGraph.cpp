#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;



bool isBipartite(vector< vector<int> > matrix, int nodes){
    vector<int> visited(nodes, 0);
    vector<int> colors(nodes, -1);//1, 2 colors
    queue<int> q;
    q.push(0);
    int color;
    bool isBipartite = true;
    set<int> allVertices;
    for(int i = 0; i < nodes; i++){
        allVertices.insert(i);
    }
    while(!allVertices.empty()){
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(allVertices.find(node) != allVertices.end()){
                allVertices.erase(node);
            }
            if(!visited[node]){
                color = colors[node]; 
                visited[node] = 1;
                for(int j = 0; j < nodes; j++){
                    if(!visited[j]){
                        q.push(j);
                        colors[j] = (color + 1)%2;
                    }

                    else {
                        if(colors[j] == color){
                            return !isBipartite;
                        }
                    }
                }
            }
        }
    }


    return isBipartite;
}

int main(){

    int nodes;
    int edges;
    cin>>nodes;
    int u, v;
    vector< vector<int> > matrix( nodes, vector<int> (nodes, 0));
    for(int i = 0; i < edges; i++){
        cin>>u>>v;
        matrix[u][v] = 1;
    }


    cout<<isBipartite(matrix, nodes)<<endl;

    return 0;
}