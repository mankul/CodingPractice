// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// 
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



// COMPLETED

#include<iostream>
// #include<string>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)
            return true;
        else    
            return false;
    }
};



int main(){
    Solution S;
    string s,t;
    cin>>s>>t;
    cout<<S.isAnagram(s,t)<<endl;

    return 0;
}
