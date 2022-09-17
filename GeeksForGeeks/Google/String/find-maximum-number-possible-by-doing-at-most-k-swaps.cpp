#include<iostream>

using namespace std;


int main(){

    string str;
    int k;
    cin>>str>>k;

    int swapCount = 0;
    for(int i = 0; i < str.length(); i++){
        int maxIndex = i;
        if(swapCount < k){
            for(int j = i+1; j < str.length();j++){
                if(str[maxIndex] < str[j]){
                    maxIndex = j;
                }
            }
            if(maxIndex != i){
                char s = str[maxIndex];
                str[maxIndex] = str[i];
                str[i] = s;
                swapCount += 1;
            }
        }
    }
    cout<<str<<endl;



    return 0;
}