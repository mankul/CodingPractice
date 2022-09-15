#include<iostream>
#include<map>
#include<vector>
using namespace std;


// works for a unique sum k
// solution 1: all suffices to all prefixes of the subarray containing ist element.
// space 1, time n^2
// store the all prefixes which includes first element.
// subtract all the suffixes in in a loop and try to find f(l) the sum - f(k) such that l < k

int uniqueSum(map<int, int> hash, int n, int k){
   int sum, count = 0;

    for(auto iter: hash){
        sum = iter.first - k;
        int i = iter.second;
        if(hash.find(sum) != hash.end()){
            int j = hash[sum];
            if(j < i){
                count+=1;
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
    map<int, int> hash;
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
        totalSum += arr[i];
        hash[totalSum] = i;
    }

    int count = uniqueSum(hash, n, k);
 

    cout<<count<<endl;
    return 0;
}