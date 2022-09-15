#include<iostream>
#include<map>

using namespace std;


int main(){

    int num;
    int k;
    cin>>num>>k;
    int arr[num];
    map<int, int> hash;
    for(int i = 0; i < num; i++){
        cin>>arr[i];
        if(hash.find(arr[i]) != hash.end())
            hash[arr[i]] += 1;
        else
            hash[arr[i]] = 1;    
    }


    for(auto iter: hash){
        if(iter.second >= (num/k))
            cout<<iter.first<<" ";
    }
    cout<<endl;

    



    return 0;
}