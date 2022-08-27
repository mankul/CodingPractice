#include <iostream>
#include<iomanip>
using namespace std;


void recurse(long num,long & root, int decimalPoint){
    if(decimalPoint == 0){
        return;
    }
    decimalPoint -= 1;
    while(root * root < num){
        root+= 1;
    }
    root = root - 1;
    // num = num - root*root;
    root *= 10;
    num = num * 100;
    recurse(num, root, decimalPoint);
}


int main() {
// your code goes here

long num;
cin>>num;
long root = 2;
int decimalPoint = 10;
recurse(num, root, decimalPoint);
cout<<setprecision(10);
cout<<( (double)root/10000000000)<<endl;
return 0;

}