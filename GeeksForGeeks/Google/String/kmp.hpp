#ifndef KMP_H
#define KMP_H
#include<map>
#include<string>
// int find_overlap(std::string str, std::map<std::string, int> prefixes, std::map<std::string, int> &overlapSuffixMatch);
// std::map<std::string, int> find_prefixes(std::string str);
int find_overlap(std::string str, std::map<std::string, int> prefixes, std::map<std::string, int> &overlapSuffixMatch){
    if(overlapSuffixMatch.find(str) != overlapSuffixMatch.end())
        return overlapSuffixMatch[str];
    int maxIndex  = 0;
    for(int i = 0; i < str.length()-1; i++){
        std::string suffix = str.substr(i+1);
        if( prefixes.find(suffix)  != prefixes.end() ){
            overlapSuffixMatch[str] = prefixes[suffix];
            return prefixes[suffix];
        }
        
    }
    overlapSuffixMatch[str] = 0;
    return 0;
}

std::map<std::string, int> find_prefixes(std::string str){
    std::map<std::string, int> prefixes;
    for(int i = 0; i< str.length(); i++){
        std::string prefix = str.substr(0,i+1);
        prefixes[prefix] = i+1;
    }

    return prefixes;
}

#endif