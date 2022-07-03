// Given an array of strings strs, group the anagrams together. 
// You can return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
// typically using all the original letters exactly once.

// COMPLETED


#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector <string> > groupAnagrams( vector<string> & strs){
        vector<vector <string> > group;
        map<string, vector<string> > mapAnagram;
        for(auto str : strs){
            string tempStr = str;
            sort(str.begin(), str.end());
            if(mapAnagram.find(str) == mapAnagram.end()){
                vector<string> stringVector;
                stringVector.push_back(tempStr);
                mapAnagram[str] = stringVector;
            }
            else{
                mapAnagram[str].push_back(tempStr);
            }
        }
        for(auto strVectorMap: mapAnagram)
            group.push_back(strVectorMap.second);
        return group;       
    }
        
    
};

int main(){

    vector<string> strs;
    int num;
    cin>>num;
    string str;
    for(int i = 0; i< num; i++){
        cin>>str;
        strs.push_back(str);
    }
    Solution s1;
    vector<vector <string> > s2 = s1.groupAnagrams(strs);

    for(auto outIter: s2){
        for(auto innerIter: outIter)
            cout<<(innerIter)<<",";
        cout<<endl;
    }
    return 0;
}