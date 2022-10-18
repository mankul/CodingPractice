#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;



void insertIntoGraph(vector< vector<int> > & matrix, int u, int v){
    matrix[u][v] = 1;
    matrix[v][u] = 1;
}


void insertIntoDirectedGraph(vector< vector<int> > & matrix, int u, int v){
    matrix[u][v] = 1;
}

// void depthFirstSearch(stack<int> nodesStack, vector< vector<int> > matrix,vector<int> & visited, int nodeIndex, int nodes, vector<int> & dfs){
//     if(nodesStack.top() == NULL && nodeIndex == nodes){
//         return ;
//     }
//     if(nodesStack.top() == NULL){
//         nodeIndex = nodeIndex+1;
//         while (nodeIndex < nodes)
//         {
//             if(visited[nodeIndex] == 0)
//                 break;
//             nodeIndex +=1;
//         }
//         nodesStack.push(nodeIndex+1);
//     }
//     if(nodeIndex >= nodes)
//         return;
//     int node;
//     while(nodesStack.top() != NULL){
//         node = nodesStack.top();
//         nodesStack.pop();
//         if(visited[node] == 0)
//             break;
//     }
//     if(nodesStack.top() == NULL && visited[node] == 1)
//         return;
//     dfs.push_back(node);
//     for(int i = 0; i < nodes; i++){
//         if(matrix[node][i] == 1)
//             if(visited[i] == 0){
//                 nodesStack.push(i);
//             }
//     }
//     depthFirstSearch(nodesStack, matrix, visited,nodeIndex,nodes,dfs);


// }






void depthFirstSearch(stack<int> nodesStack, vector< vector<int> > matrix, int nodes, vector<int> & visited, int nodeIndex, vector<int> & dfs){
    if(nodesStack.empty() && nodeIndex >= nodes)
        return;
    else if(nodesStack.empty() && nodeIndex < nodes){
        int node = nodeIndex;
        if(visited[node] == 1)
            nodeIndex += 1;
        else
            nodesStack.push(node);
    }
    else{
        int node = nodesStack.top();
        nodesStack.pop();
        if(visited[node] == 0){
            dfs.push_back(node);
            visited[node] = 1;
            for(int i = 0; i < nodes; i++)
                if(matrix[node][i] == 1 && visited[i] == 0)
                    nodesStack.push(i);
        }
    }
    depthFirstSearch(nodesStack, matrix, nodes, visited, nodeIndex, dfs);
}



void breadhFirstSearch(vector< vector<int> > matrix, queue<int> q, vector<int> & visited, int nodeIndex, int nodes, vector<int> & traversal){
    if(q.empty() && nodeIndex >= nodes)
        return;
    else if(q.empty() && nodeIndex < nodes){
        int node = nodeIndex;
        if(visited[node] == 1)
            nodeIndex += 1;
        else 
            q.push(node);
    }
    else{
        int node = q.front();
        q.pop();
        if(visited[node] == 0){
            traversal.push_back(node);
            visited[node] = 1;
            for(int i = 0; i < nodes; i++){
                if(matrix[node][i] == 1 && visited[i] == 0)
                    q.push(i);
            }
        }
    }
    breadhFirstSearch(matrix, q, visited, nodeIndex, nodes, traversal);
}




void topologicalSorting(vector< vector<int> > matrix, int nodes, vector<int> & traversal) {
    // throw "topological sorting not applied";
    vector<int> visited(nodes, 0);
    vector<int> incomingEdges(nodes, 0);
    queue<int> q;
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++){
            if(matrix[i][j] == 1){
                incomingEdges[j] += 1;
            }
        }
    }
    for(int i = 0; i < nodes; i++){
        if(incomingEdges[i] == 0)
            q.push(i);
    }
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        visited[node] = 1;
        traversal.push_back(node);
        for(int nbr = 0; nbr < nodes; nbr++){
            // if(visited[nbr] == 1){
                // return !DAG;
                // throw "NOT A DAG";
            // }
            if(matrix[node][nbr] == 1 && visited[nbr] == 0){
                incomingEdges[nbr] -= 1;
                if(incomingEdges[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
    for(int i = 0; i < nodes; i++){
        if(incomingEdges[i] > 0){
            // return !DAG;
            throw "NOT A DAG";
        }
    }
}
void printTraversal(vector<int> dfs){
    for(auto iterator: dfs)
        cout<<iterator<<endl;
    
}


void printGraph(vector< vector<int> > matrix){
    for(auto iterator: matrix){
        for(auto ind: iterator){
            cout<<ind;
        }
        cout<<endl;
    }
}




int main(){


    int nodes, edges;
    cin>>nodes>>edges;
    int u,v;
    vector<int> outNodes(nodes, 0);
    vector< vector<int> > matrix(nodes, vector<int> (nodes, 0));
    vector< vector<int> > directedMatrix( nodes, vector<int> (nodes, 0));

    vector<int>  visited(nodes, 0);
    for(int i = 0; i< edges; i++){
        cin>>u>>v;
        insertIntoGraph(matrix, u, v);
        insertIntoDirectedGraph(directedMatrix, u, v);
        outNodes[u] = 1;
    }

    stack<int> nodesStack;
    vector<int> dfs;

    int nodeIndex = 0;
    depthFirstSearch(nodesStack, matrix, nodes, visited, nodeIndex, dfs);

    vector<int> visitedBfs(nodes, 0);

    queue<int> q;
    vector<int> bfs;
    nodeIndex = 0;
    breadhFirstSearch(matrix,q, visitedBfs, nodeIndex, nodes, bfs );

    printGraph(matrix);
    cout<<"Depth First Search Traversal"<<endl;
    printTraversal(dfs);
    cout<<"Breadth First Search Traversal"<<endl;
    printTraversal(bfs);
    vector<int> topoSort;
    cout<<"Directed Graph"<<endl;
    printGraph(directedMatrix);
    cout<<"Topological Sorting"<<endl;
    try{
        topologicalSorting(directedMatrix, nodes, topoSort);
        printTraversal(topoSort);
    }
    catch(const char * excep){
        cout<<excep<<endl;
    }
    catch(char * excep){
        cout<<excep<<endl;
    }
    catch(string excep){
        cout<<excep<<endl;
    }
    
    catch(void * excep){
        cout<<excep<<endl;
    }
    catch( ... ){
        cout<<"Default exception"<<endl;
    }
    
    return 0;
}