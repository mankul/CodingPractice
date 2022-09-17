#include<iostream>
#include<map>
using namespace std;




int find_overlap(string str, map<string, int> prefixes, map<string, int> &overlapSuffixMatch){
    if(overlapSuffixMatch.find(str) != overlapSuffixMatch.end())
        return overlapSuffixMatch[str];
    int maxIndex  = 0;
    for(int i = 0; i < str.length()-1; i++){
        string suffix = str.substr(i+1);
        if( prefixes.find(suffix)  != prefixes.end() ){
            overlapSuffixMatch[str] = prefixes[suffix];
            return prefixes[suffix];
        }
        
    }
    overlapSuffixMatch[str] = 0;
    return 0;
}

map<string, int> find_prefixes(string str){
    map<string, int> prefixes;
    for(int i = 0; i< str.length(); i++){
        string prefix = str.substr(0,i+1);
        prefixes[prefix] = i+1;
    }
}



int main(){


    string s,s1;
    cin>>s>>s1;



    for(int i = 0; i < s.length(); i++){

    }
}