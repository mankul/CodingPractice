#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<int, int> newMap;
    for(int i = 0;i < 10; i++){
        if(newMap[i] < i){
            newMap[i] = i+10;
        }
    }
    for(auto iter: newMap){
        cout<<iter.first<<"\t"<<iter.second<<endl;
    }

    return 0;
}