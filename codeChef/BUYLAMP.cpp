#include <iostream>
using namespace std;

int main() {


    int t;
    int n, k;
    int x, y;
    cin>>t;
    for(int i = 0; i < t; i++){
        cin>>n>>k>>x>>y;
        cout<<k*x + (n-k) * (x>y? y: x)<<endl;
    }


	// your code goes here
	return 0;
}
