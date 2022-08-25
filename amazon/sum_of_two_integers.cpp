#include<iostream>
#include<vector>
#include<map>
using namespace std;


int main(){

    int number;

    int size, target;
    cin>>target;
    cin>>size;
    vector<int> array;
    map<int, int> hash;
    bool found = false;
    for(int i = 0; i< size; i++){
        cin>>number;
        if(hash.find(target - number) == hash.end()){
            hash[number] = i;// storing index
        }
        else{
            found = true;
            cout<<number<<" "<<target-number<<endl;
            break;
        }
    }
    if(!found)
        cout<<"not found"<<endl;




    return 0;

}