// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.


// COMPLETED


#include<iostream>

using namespace std;
class Solution {
public:
    bool checkInclusion(string s2, string s1) {
        int s2Dict[26] = {0};
        int s1Dict[26] = {0};
        int sizes1 = s1.size();
        int sizes2 = s2.size();
        if(sizes2 > sizes1)
            return false;
        for(int i = 0; i< sizes2; i++){
            s2Dict[s2[i] - 'a']+=1;
        }    
        for (int i = 0; i < sizes2; i++)
        {
            s1Dict[s1[i] - 'a']+=1;
        }
        bool foundMatch= true;
        for(int i = 0; i < 26; i++){
            if(s1Dict[i] != s2Dict[i]){
                foundMatch = false;
                break;
            }
        }
        if(foundMatch == true){
            return true;
        }
        for(int i = 0; i < sizes1 - sizes2; i++){
            foundMatch = true;
            s1Dict[s1[i] - 'a' ] -= 1;
            s1Dict[s1[i+sizes2] - 'a'] += 1;
            for(int j = 0; j <  26; j++){
                if(s1Dict[j] != s2Dict[j]){
                    foundMatch = false;
                    break;
                }
            }
            if(foundMatch == true){
                return true;
            }
        }
        return false;
    }
};

int main(){

    string s1, s2;
    cin>>s1>>s2;
    Solution s;
    cout<<s.checkInclusion(s1, s2)<<endl;
    return 0;
}