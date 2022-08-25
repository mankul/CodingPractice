#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main(){



    int t, n;
    long number;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n;
        vector<long> array;
        map<long, int> hash;
        for(int j = 0; j < n; j++){
            cin>>number;
            array.push_back(number);
            if(hash.find(number) == hash.end()){
                hash[number] = 1;
            }
            else{
                hash[number]+= 1;
            }
        }
        bool found = true;
        for(auto iterator = hash.begin(); iterator != hash.end(); iterator++){
            if(iterator->second > (n+1)/2) {
                found = false;
                break;
            }
        }
        if(found)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;

}