#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    std::string name;
    std::string number;
    std::map<std::string, std::string> dictionary;
    for(int i = 0 ; i < n; i++){
        cin>>name;
        cin>>number;
        dictionary[name] = number;
    }  
    while(cin>>name){
        if(dictionary.find(name) == dictionary.end()){
		cout<<"Not Found"<<endl;
	}
	else{
		cout<<dictionary[name]<<endl;
	}
    }
    return 0;
}
