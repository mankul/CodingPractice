/*
Problem
Chef has a rectangular plate of length N cmN and width M cm. He wants to make a wireframe around the plate. The wireframe costs XX rupees per cm.

Determine the cost Chef needs to incur to buy the wireframe.

Input Format
First line will contain TT, the number of test cases. Then the test cases follow.
Each test case consists of a single line of input, containing three space-separated integers N,M,N,M, and XX — the length of the plate, width of the plate, and the cost of frame per cm.
Output Format
For each test case, output in a single line, the price Chef needs to pay for the wireframe.

*/







#include<iostream>

using namespace std;


int main(){


    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n, m, x;
        cin>>n>>m>>x;
        cout<<2*x*(n+m)<<endl;
    }



    return 0;
}