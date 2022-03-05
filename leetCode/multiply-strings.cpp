// Given two non-negative integers num1 and num2 represented as strings, 
// return the product of num1 and num2, also represented as a string.
// Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
#include<iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string multiplyAns="";
        int len1 = num1.size();
        int len2 = num2.size();
        int carry, number1, number2;
        for(int i = len1-1; i >= 0; i--){
            carry = 0;
            string iterationMultiply = "";
            for(int j = len2-1; j>=0;j--){
                number1 = (num1[i]-'0');
                number2 = (num2[j]-'0');
                carry+=(number1 * number2);
                iterationMultiply.insert(0,to_string(carry%10));
                carry = carry/10;

            }
            if(carry>0)
                iterationMultiply.insert(0, to_string(carry));
            
            for(int k = 0; k < len1-1-i; k++)
                iterationMultiply.append(to_string(0));
            
            carry = 0;
            reverse(multiplyAns.begin(), multiplyAns.end());
            reverse(iterationMultiply.begin(), iterationMultiply.end());
            string temp = "";
            for(int j = 0; j < max(iterationMultiply.size(), multiplyAns.size());j++){
                if(j< iterationMultiply.size() && j < multiplyAns.size()){
                    carry += (iterationMultiply[j] - '0') + (multiplyAns[j] - '0');
                }
                else if(j >= iterationMultiply.size()){
                    carry += (multiplyAns[j] - '0');
                }
                else{
                    carry += (iterationMultiply[j] - '0');
                }
                temp.append(to_string(carry%10));
                carry = carry / 10;
            }
            if(carry != 0){
                string carryString  = to_string(carry);
                reverse(carryString.begin(), carryString.end());
                temp+=carryString;
            }
            reverse(temp.begin(), temp.end());
            multiplyAns = temp;
        }
        if(multiplyAns[0] == '0')
            multiplyAns = "0";
        return multiplyAns;
    }
};

int main(){
    Solution s;
    string sol = s.multiply("234323443","0");
    if(sol[0] == '0')
        cout<<sol[0];
    else
        cout<<sol;
        
    
}