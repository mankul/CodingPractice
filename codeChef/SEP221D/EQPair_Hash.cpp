// solution of eqpair with hashing 



#include<iostream>
#include<map>
#include<vector>

#define unit long long



using namespace std;



int main(){


    int t;
    cin>>t;
    for(int i = 0; i < t; i++){
        int n;
        cin>>n;
        vector<unit> arr(n);
        map<unit, int> hash; 
        for(int i = 0; i < n ; i++){
            cin>>arr[i];
            if( hash.find(arr[i]) == hash.end()){
                hash[arr[i]] = 1;
            }
            else{
                hash[arr[i]] += 1;
            }
        }

        unit pairs = 0;
        for( auto iterator = hash.begin(); iterator != hash.end(); iterator++){
            pairs += (iterator->second * (iterator->second - 1))/2;
        }
        cout<<pairs<<endl;
    }



    return 0;
}