#include<iostream>
#include<string>
#include<vector>


using namespace std;


int main(){

    //  sentence is input comma seperated


    string input;
    getline(cin, input);
    string delimeter= " ";

    vector<string> stringArray;

    size_t pos = 0;
    while( (pos = input.find(delimeter)) != string::npos){
        string word = input.substr(0, input.find(delimeter));
        stringArray.push_back(word);
        input.erase(0, pos + delimeter.length() );
    }
    if(input.length() > 0)
    {
        stringArray.push_back(input);
    }

    int numberOfWords = stringArray.size();
    for(int i = 0; i < numberOfWords; i++){
        cout<<stringArray[numberOfWords-1-i]<<endl;
    }


    return 0;
}