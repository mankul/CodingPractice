#include<iostream>

using namespace std;



/*
For all the prefixes of s, match suffix with s1 and replace the matching with s2.
*/








int main(){


    string s, s1, s2;


    cin>>s>>s1>>s2;


    for(int i = 0; i < s.length(); i++){
        int k = s1.length()-1;
        for(int j = i; j >= 0; j--){
            if(s[j] != s[k])
                break;
            else
                k-=1;
            if(k == -1)
            {
                s.erase(i-s1.length()+1, s1.length());
                s.insert(i-s1.length()+1, s2);
            }
        }
    }

    cout<<s<<endl;


    return 0;
}