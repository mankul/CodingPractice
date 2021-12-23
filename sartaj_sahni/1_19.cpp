// compute n! in non recursive manner
#include<iostream>
#include<vector>
#include<map>

using namespace std;


int main(){

    int num;
    cin>>num;
    // vector< pair<int, int> >dictionary;
    map< int, int > second_dictionary;

    for(int i = 0; i < num; i++){
        second_dictionary[i] = i + 10;
        
    }
    for(map<int, int> ::iterator i = second_dictionary.begin(); i != second_dictionary.end(); i++)
    cout<<i->first<<"\t"<<i->second<<endl;

        // cout<<second_dictionary[i]<<endl;
    
    return 0;
}