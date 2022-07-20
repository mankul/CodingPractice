// You are given two positive integers n and k. 
// A factor of an integer n is defined as an integer i where n % i == 0.
// Consider a list of all factors of n sorted in ascending order, 
// return the kth factor in this list or return -1 if n has less than k factors.

#include<iostream>
#include<map>
#include<vector>

using namespace std;


class Solution {
public:
    int kthFactor(int n, int k) {
        int factor = 1;
        // map<int, int> hashFactor ;
        vector<int> factorList;
        vector<int> reverseFactorList;
        while(factor <= sqrt(n)){
            // if(hashFactor.find(factor) == hashFactor.end()
            if(n%factor == 0){
                factorList.push_back(factor);
                if(factor != sqrt(n))
                    reverseFactorList.push_back(n/factor);
            }
            factor += 1;
        }
        for(int i = reverseFactorList.size() - 1; i >= 0; i--)
            factorList.push_back(reverseFactorList[i]); 
        for(int i = 0; i < factorList.size();i++)
            cout<<factorList[i]<<endl;
        if(k <= factorList.size())
            return factorList[k-1];
        else    
            return -1;
    }
};

int main(){
    Solution s;
    // cout<<s.kthFactor(12,2);
    // cout<<s.kthFactor(25,5);
    cout<<s.kthFactor(7,2);

    return 0;
}