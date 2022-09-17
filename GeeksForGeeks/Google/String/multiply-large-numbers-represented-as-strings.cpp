#include<iostream>


using namespace std;


int main(){


    string a,b;
    cin>>a>>b;
    int lengtha = a.length();
    int lengthb = b.length();
    string output="";
    string current_sum = "";
    int carry = 0;
    int sum = 0;
    for(int i = lengtha-1 ; i >= 0; i--){
        current_sum = "";
        for(int j = lengthb-1; j >= 0; j--){
            sum = (b[j] - '0') * (a[i] - '0') + carry;
            carry = sum/10;
            sum = sum%10;
            current_sum += to_string(sum) ;
        }
        for(int k = 0 ; k < lengtha - 1 - i; k++)
            current_sum.insert(k, "0");
        // cout<<"current sum "<<current_sum<<endl;

        int j = 0, k = 0;
        carry = 0;
        string temp_string= "";

        while(j < current_sum.length() || k < output.length()){
            if(j == current_sum.length()){
                carry += (output[k]-'0');
                k++;
            }
            else if(k == output.length()){
                carry += (current_sum[j] - '0');
                j++;
            }
            else{
                carry += (current_sum[j] - '0') + (output[k] - '0');
                j++;
                k++;
            }
            temp_string+= to_string(carry%10);
            carry = carry/10;
        }
        while(carry != 0){
            temp_string+= to_string(carry%10);
            carry /= 10;
        }
        output = temp_string;
        // cout<<"output "<<output<<endl;
    }

    current_sum = "";
    for(int i = 0; i < output.length(); i++){
        current_sum.insert(0,1,output[i]);
    }


    cout<<current_sum<<endl;
    



    return 0;
}