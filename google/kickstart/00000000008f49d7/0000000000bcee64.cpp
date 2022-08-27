#include<iostream>


using namespace std;

int main(){

    int t;
    cin>>t;
    int m, n, candy;
    for(int i = 0; i < t ; i++){
        cin>>n>>m;
        long candies = 0;
        for(int  j = 0; j < n; j++){
            cin>>candy;
            candies+=(candy%m);
        }
        int remainder = candies%m;
        cout<<"Case #"<<i+1<<": "<<remainder<<endl;
    }


    return 0;
}