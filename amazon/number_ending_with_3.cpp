// find the smallest number 111...11 which is multiple of number ending with xy...3

#include<iostream>
using namespace std;


int main(){
    int num;
    cin>>num;
    int count=1;
    int modularNumber = 1;
    while(modularNumber % num !=  0){
        modularNumber *= 10 ;
        modularNumber = modularNumber % num;
        modularNumber += 1;
        count++;
    }
    string s = "";
    for(int i = 0; i < count; i++)
        s+="1";
    cout<<s<<endl;
    return 0;
}
