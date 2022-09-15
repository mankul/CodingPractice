#include<iostream>
#include<map>
#include<vector>
using namespace std;


// works for a unique sum k
// solution 1: all suffices to all prefixes of the subarray containing ist element.
// space 1, time n^2
// store the all prefixes which includes first element.
// subtract all the suffixes in in a loop and try to find f(l) the sum - f(m) such that l < m
// for all the indices smaller than the indices of bigger value for which the difference is sum = k, 


// complexity, let there are p such sub arrays. then the complexity is \theta(n + p).

int multipleSum(map<int, vector<int> > hash, int n, int k){
    int count = 0;
    for(auto iter: hash){
        int sum = iter.first - k;
        if(hash.find(sum) != hash.end()){
            vector<int> arr = hash[sum];
            for(auto i: arr){
                for(auto j: iter.second)
                    if( i < j){
                        count +=1;
                    }
            }
        }
    }
    return count;
}


int main(){


    int k, n;
    cin>>k;
    cin>>n;
    
    int arr[n];
    int totalSum = 0;
    map<int, vector<int> > multipleHash;
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
        totalSum += arr[i];
        if(multipleHash.find(totalSum) != multipleHash.end()){
            multipleHash[totalSum].push_back(i);
        }
        else{
            vector<int> arr;
            arr.push_back(i);
            multipleHash[totalSum] = arr;
        }
    }

    int count = multipleSum(multipleHash, n, k);
    cout<<count<<endl;
    return 0;
}