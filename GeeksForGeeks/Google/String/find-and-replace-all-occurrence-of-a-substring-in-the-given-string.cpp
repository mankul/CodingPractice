#include<iostream>


using namespace std;


int main(){

    string s, s1, s2;
    cin>>s>>s1>>s2;
    int left = 0;
    int k = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == s1[k]){
            k+=1;
            if(k == s1.length()){
                s.erase(left, s1.length());
                s.insert(left, s2);
                k=0;
                left=i+1;
            }
        }
        else{
            i = left;
            k=0;
            left = i+1;
        }
    }

    cout<<s<<endl;
    return 0;
}