// Given two binary strings a and b, return their sum as a binary string.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int size_a = a.size();
        int size_b = b.size();
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string str = "";
        int carry = 0;
        for(int i = 0,j = 0; i< size_a|| j<size_b;i++,j++){
            if(i < size_a && j < size_b)
                carry += (a[i] - '0') + (b[j] - '0');
                
            else if(i<size_a)
                carry += (a[i] - '0');
            else if(j < size_b)
                carry += (b[j] - '0');
            else{
                break;
            }
            str.insert(0,to_string(carry%2));
            carry = carry/2;
        }

        if(carry != 0){
            str.insert(0,to_string(carry ));
        }
        return str;
    }
};

int main(){
    string a = "1010000";
    string b = "1111111";

    Solution s;
    cout<<a<<"\t+\t"<<b<<"\t=\t"<<s.addBinary(a,b);

    return 0;
}