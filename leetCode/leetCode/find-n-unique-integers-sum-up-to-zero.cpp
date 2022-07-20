// Given an integer n, return any array containing n unique integers such that they add up to 0.

#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> sum;
        int count = 0;
        if(n%2 != 0)
            sum.push_back(0);
        while(count < n/2){
            count ++;
            sum.push_back(count);
            sum.push_back(-count);            
        }
        return sum;
    }
};

int main(){


    return 0;
}