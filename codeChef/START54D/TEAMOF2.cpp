#include <iostream>
#include<vector>
using namespace std;


int main() {
    
    int test, n;
    cin>>test;
    string questions;
    string del = " ";
    for(int t = 0; t < test; t++){
        cin>>n;
        int arr[n][5];
        for(int i = 0 ; i < n; i++){
            getline(cin, questions);
            int index = 0;
            int start = 0;
            while( index < questions.size()){
                index = questions.find(del, start );
                int number = (int)(questions.substr(start, index));
            }
        }    
    }
    
	// your code goes here
	return 0;
}
