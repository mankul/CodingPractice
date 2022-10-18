#include<iostream>

using namespace std;


// c99 
// void insertIntoMatrix(int nodes,int u, int v, int matrix[][nodes]){
// void insertIntoMatrix(int (*matrix)[nodes], int u, int v){


void insertIntoMatrix( int * matrix, int u, int v, int nodes){
    *(matrix + nodes * u + v) = 1;
    *(matrix + nodes * v + u) = 1;
    // matrix[u][v] = 1;
    // matrix[v][u] = 1;
}


void printGraph(int * matrix, int nodes){
    for(int i = 0; i < nodes; i++){
        for(int j = 0; j < nodes; j++)
            cout<<*(matrix + i*nodes + j);
        cout<<endl;
    }
}



int main(){

    int nodes;
    cin>>nodes;
    int arr[nodes][nodes] = {0};

    int edges;
    cin>>edges;
    int u, v;
    for(int i = 0 ; i < edges; i++){
        cin>>u>>v;
        insertIntoMatrix( (int *)arr, u, v, nodes);
    }

    printGraph((int *)arr, nodes);

    return 0;
}