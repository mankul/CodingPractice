// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// 
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


// COMPLETED

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int size_s = s.size();
        int size_p = p.size();
        
        vector<int> indices;
        if(size_p>size_s)
            return indices;
  /*      // sort(p.begin(), p.end());*/
        int charArray[26] = {0};
        int stringCharArray[26] = {0};
        for(int i = 0; i< size_p; i++)
            charArray[p[i] -'a'] +=1;

        for(int i = 0; i < size_p; i++){
            stringCharArray[s[i] - 'a'] += 1;
        }
        bool anagramEqual = true;
        for(int j = 0; j< 26; j++)
            if(stringCharArray[j] != charArray[j])
            {
                anagramEqual = false;
                break;
            }
        if(anagramEqual == true){
            indices.push_back(0);
        }
        
        for(int i = size_p; i < size_s; i++){
            anagramEqual = true;
         
            stringCharArray[s[i-size_p]-'a']-=1;
            stringCharArray[s[i]-'a']+=1;
            for(int j = 0; j < 26; j++)
                if(stringCharArray[j] != charArray[j]){
                    anagramEqual = false;
                    break;
                }
            if(anagramEqual == true)
                indices.push_back(i-size_p+1);
        }
/*

        for(int i = 0; i < size_s-size_p + 1; i++){
            bool anagramMatch = true;
            int stringArray[26] = {0};
            for(int j = i; j < i+size_p;j++)
                stringArray[s[j] - 'a'] +=1;

            for(int j = 0; j < 26; j++){
                if(charArray[j] != stringArray[j])
                {
                    anagramMatch = false;
                    break;
                }
            }

            if(anagramMatch == true)
                indices.push_back(i);
              */  
           /* 
           // string t = s.substr(i,size_p);
            // sort(t.begin(), t.end());
            // if(t == p){
            //     indices.push_back(i);
            // }
        }*/
        
        return indices;
    }
};

int main(){

    Solution S;
    string s,p;
    cin>>s>>p;
    vector<int> indices = S.findAnagrams(s,p);
    for(auto iterator = indices.begin(); iterator!= indices.end();iterator ++)
        cout<<*iterator<<", ";
    cout<<endl;
    return 0;

}
