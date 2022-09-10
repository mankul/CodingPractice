#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int test;
	int n;
	int k;
	string str;
	cin>>test;
	long modulo = 1;
    for(int i = 0; i< 9; i++)
        modulo *= 10;
    modulo += 7;
	for(int t = 0; t < test; t++){
	    cin>>n>>k;
	    cin>>str;
	    long long ans = 1;
        if(n == k)
            ans = 2;
        else
	        for(int i = 0; i < n; i++){
	            ans = (ans * 2)%(modulo);
	        }
        cout<<ans<<endl;
	}
	return 0;
}
