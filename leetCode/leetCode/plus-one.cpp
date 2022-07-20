// You are given a large integer represented as an integer array digits, 
// where each digits[i] is the ith digit of the integer. 
// The digits are ordered from most significant to least significant in left-to-right order. 
// The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.


#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        cout<<size<<endl;
        for(int i = size - 1; i>=0 ; i--){
            cout<<i<<"\t"<<digits[i]<<endl;
            carry+=digits[i];
            digits[i] = carry%10;
            carry/=10;
        }
        if(carry > 0){
            digits.insert(digits.begin(),carry);
        }
        return digits;
    }


};


int main(){
    // Solution s;
    vector<int> arr(3,3);
    s.plusOne(arr);
    for(int i = 10; i-- ; i>=0)
        cout<<i<<endl;
    for(int i = 0; i< 10; i++)
        cout<<i<<endl;

    return 0;
}