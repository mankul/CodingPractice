#include<iostream>
#include"kmp.hpp"

using namespace std;







int main(){


    string s,s1;
    cin>>s>>s1;

    map<string, int> prefixes;
    map<string, int> overlapSuffixMatch;

    prefixes = find_prefixes(s1);

    for(int i = 0; i < s1.length(); i++){
        string str = s1.substr(0, i+1);
        overlapSuffixMatch[str] = find_overlap(str, prefixes, overlapSuffixMatch);
    }

    for(auto iterator: prefixes){
        cout<<iterator.first<<" "<<iterator.second<<endl;
    }

    cout<<" **** *** ** "<<endl;
    for(auto iterator: overlapSuffixMatch){
        cout<<iterator.first<<" "<<iterator.second<<endl;
    }


    int i = 0;
    int j = 0;
    while(i < s.length()){
        while(j < s1.length()){
            if(s[i] == s1[j]){
                i++;
                j++;
            }
            else{
                string subst = s1.substr(0, j);
                int overlap = overlapSuffixMatch[subst];
                int step = max(1, j - overlap);
                j = step;
                i = i - step;
                break;
            }
        }

        if(j > s1.length()){
            cout<<"found"<<endl;
            break;
        }
    }




}