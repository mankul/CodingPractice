// Given an array A[ ] of positive integers of size N, where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are M students, the task is to distribute chocolate packets among M students such that :
// 1. Each student gets exactly one packet.
// 2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.

#include<vector>
#include<iostream>
using namespace std;
class Solution{
    public:

    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    long long i, j;
    for (i = 0 ; i < n; i++){
        long long k = 0, temp;
        for ( j = i-1 ; j >= 0; j--){
            if(a[i] > a[j])
                k = j+1;
        }
        for( long long l = i; l > k; l--){
            temp = a[l];
            a[l] = a[l-1];
            a[l-1] = temp;
        }
    }
    for(auto x: a){
        std::cout<<x<<": \t";
    }
    long long minSize = a[n - 1] - a[n-1-m];
    for(int i = 0; i < n ; i++){
        if( (a[i+n] - a[i]) > minSize)
            minSize = a[i + n] - a[i];
    }
    return minSize;
    }   

};

int main(){
    Solution s;
    long long n, num, m;
    vector<long long> a;
    cin>>n>>m;
    for(auto i = 0; i < n; i++){
        cin>>num;
        a.push_back(num);
    }
    long long res = s.findMinDiff(a, n, m);
    std::cout<<res<<std::endl;
    return 0;
}