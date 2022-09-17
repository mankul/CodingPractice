#include<iostream>
#include<map>

using namespace std;


#define MAX_LENGTH 10000


int main(){

    string a, b;
    cin>>a>>b;
    int minIndex = MAX_LENGTH;  
    for(int i = 0 ; i < a.length(); i++){
        for(int j = 0 ; j < b.length(); j++){
            if(a[i] == b[j]){
                if(j < minIndex)
                    minIndex = j;
                break;
            }
        }
    }
    if(minIndex < MAX_LENGTH)
        cout<<b[minIndex]<<" "<<minIndex<<endl;
    else
        cout<<"not found"<<endl;



    return 0;
}