#include<iostream>


using namespace std;




int main(){

    int n, m;
    cin>>n>>m;
    int vis;
    int alive_max_index;
    int array_ [n];
    int j = 0;
    for(int i = 0; i < n+m; i++)
        cin>>vis;
        if (vis == -1){

        }
        else{
            array_[j] = vis;
            j+=1;
        }

    return 0;
}