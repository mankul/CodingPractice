#include <iostream>
#include<vector>
#include<map>
using namespace std;



long mod(long val){
    return val<0?-val:val;
}

long minimum(long a, long b){//}, long c){
    return a < b ? a : b; //< c? a: c : b < c ? b: c;
}

long reduce(long &a, long &b){
    long min_sum = mod(a) + mod(b);
    while(1){
        a-= 1;
        b-= 2;
        if( ( mod(a) + mod(b) ) < min_sum)
            min_sum = mod(a) + mod(b);
        else
            break;
    }
    return min_sum;
}


long f(map<long, long> & hash, vector<long> array, int k, int n){
    if(hash.find(k) != hash.end())
        return hash[k];
    if(k>n)
        return 0;
    if(k == n){
        return mod(array[k]);
    }
    long hash1 , hash2;

    if(hash.find(k+1) == hash.end())
        hash1 = f(hash, array , k + 1, n);
    else
        hash1 = hash[k+1];

    if(hash.find(k+2) == hash.end())
        hash2 = f(hash, array, k + 2, n);
    else
        hash2 = hash[k+2];

    hash[k] = minimum(
                    mod(array[k]) + hash1, \
                    reduce( array[k] , array[k+1] ) +  hash2 \
                    );
    return hash[k];
}


int main() {


    int t, n;
    cin>>t;
    for(int i = 0; i < t; i++){

        cin>>n;
        long number;
        vector<long> array;
        map<long, long> hash;
        for(int j = 0; j < n; j++){
            cin>>number;
            array.push_back(number);
        }
        cout<<f(hash, array, 0, n-1)<<endl;

    }


	// your code goes here
	return 0;
}
