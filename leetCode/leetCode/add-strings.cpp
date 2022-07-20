// Given two non-negative integers, num1 and num2 represented as string, 
// return the sum of num1 and num2 as a string.
// You must solve the problem without using any built-in library for handling large integers 
// (such as BigInteger). 
// You must also not convert the inputs to integers directly.


#include<iostream>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        string output="";
        int size1 = num1.size();
        int size2 = num2.size();
        for(int i = size1 - 1, j = size2-1; i>= 0 || j >= 0; i--,j--){
            if(i >= 0 && j >=0)
                carry += (num1[i] - '0') + (num2[j] - '0');
            else if(i >= 0)
                carry += (num1[i]- '0');
            else if( j >= 0)
                carry += (num2[j] - '0');
            output.insert(0,to_string(carry%10));
            carry /= 10;
        }
        while (carry>0)
        {
            output.insert(0,to_string(carry%10));
            carry/=10;
        }

        return output;
    }
};

int main(){
    string a = "0", b = "0";
    Solution s;
    cout<<s.addStrings(a,b);
    return 0;
}