#include<iostream>
#include<map>

using namespace std;

// complexity O(2^n)


bool isStringSegmentable(map<string, int> dictionary, string input, int startingIndex, int index, int lengthOfString){
    if(index > lengthOfString)
        return false;
    if(index == lengthOfString ){
        string word = input.substr(startingIndex, index);
        return (dictionary.find(word) != dictionary.end()) ? true: false;
    }
    string word = input.substr(startingIndex, index);
    if(dictionary.find(word) != dictionary.end()){
        bool result = isStringSegmentable(dictionary, input, index, index+1, lengthOfString);
        if(result)  
            return result;
    }
    return isStringSegmentable(dictionary, input, startingIndex, index+1, lengthOfString);
}


int main(){


    // input map of words

    map<string, int> dictionary;
    int dictionaryCount;
    cin>>dictionaryCount;
    for(int i = 0; i < dictionaryCount; i++){
        string key;
        cin>>key;
        dictionary[key] = 1;
    }

    string input_string;
    cin>>input_string;
    int lengthOfString = input_string.size();
    
    bool result = isStringSegmentable(dictionary, input_string, 0, 0, lengthOfString);
    cout<<result<<endl;


    return 0;
}