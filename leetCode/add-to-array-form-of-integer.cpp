// The array-form of an integer num is an array representing its digits in left to right order.
// For example, for num = 1321, the array form is [1,3,2,1].
// Given num, the array-form of an integer, and an integer k, return the array-form of the integer num + k.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int size = num.size();
        int carry = k;
        for(int i = size - 1; i>= 0; i--){
            carry += num[i];
            num[i] = carry%10;
            carry /=10;
        }
        while(carry > 0){
            num.insert(num.begin(),carry%10);
            carry/=10;
        }
        return num;
    }
};

int main(){

    vector<int> vec;
    for(int i = 1; i < 9;i++){
        vec.push_back(i);
    }
    Solution a;
    for(int k =  1000000; k < 100000000; k+=10000000){
        vec = a.addToArrayForm(vec,k);
        for(int i = 0; i <  vec.size();i++)
                    cout<<vec[i];
    cout<<endl;
    }
    return 0;
}