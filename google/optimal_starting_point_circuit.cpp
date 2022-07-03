// N gas stations in circuit. Car will move in clockwise direction. At station i
// A_i gas will be filled and B_i is fuel consumtion between i  to i+1.
// Find the optimal place to start car from, where if fuel <0 in between stations.
// the car will halt.


#include<iostream>
#include<vector>
using namespace std;


int findOptimalPlaceInCircuit(vector<int> A, vector<int> B, int N){
    int j = N-1, fuel = 0;
    int i = 0;
    while( i > j){
        if(fuel >= 0){
            fuel += A[i] - B[i];
            i+=1;
        }
        if(fuel < 0){
            fuel += A[j] - B[j];
            j-=1;
        }
    }
    if(fuel < 0 )
        return -1;
    return (i)%N;
}


int main(){

    vector<int> A;
    vector<int> B;

    int N;// circuit nodes
    cout<<"enter N"<<endl;
    cin>>N;
    int a,b;
    cout<<"enter the respective A and B with spaces"<<endl;
    for(int i = 0; i < N; i++){
        cin>>a>>b;
        A.push_back(a);
        B.push_back(b);
    }
    cout<<findOptimalPlaceInCircuit(A,B,N);
    return 0;
}