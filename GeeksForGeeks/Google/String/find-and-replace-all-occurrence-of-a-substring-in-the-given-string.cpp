#include<iostream>
#include"kmp.hpp"



using namespace std;

// buggy

/*
For all the prefixes of s, match suffix with s1 and replace the matching with s2.
*/




void bruteForce(string s, string s1, string s2){
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

}





int main(){


    string str, pattern, match;
    cin>>str>>pattern>>match;

    // bruteForce(s, s1, s2);

    std::map<std::string, int> prefixes = find_prefixes(pattern);
    std::map<std::string, int> overlapSuffixes;

    for(auto prefix: prefixes){
        cout<<prefix.first<<" - "<<prefix.second<<endl;
    }

    int i = 0;
    int j = 0;
    int str_length = str.length();
    int pattern_length = pattern.length();
    int match_length = match.length();
    while( i < str_length ){
        j = 0;
        while( j < pattern_length ){
            if(str[i] != pattern[j]){
                int overlap = find_overlap(pattern.substr(0,j+1), prefixes, overlapSuffixes);
                // int stepback = j - overlap;
                j = overlap;
            }
            i+=1;
            j+=1;
        }
        if(j == pattern_length){
            str.erase(i - pattern_length - 1, pattern_length);
            str.insert(i - pattern_length - 1,match);
            i = i - pattern_length  + match_length;
            i+=1;
        }
    }

    cout<<str<<endl;
    return 0;
}