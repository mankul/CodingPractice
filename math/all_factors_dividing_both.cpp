#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

#define unit long long 
unit gcd(unit a, unit b){
	if(a == b )
		return a;
	if(a > b){
		if(a % b != 0)
			return gcd(b, a%b);
		return b;
	}
	else{
		return gcd(b,a);
	}
	
}

int main() {
	unit num1, num2;
	cin >> num1 >> num2;
	unit gc = gcd(num1, num2);
	unit count = 1;

	vector<unit> dictionary;
	unit i = 2;
	unit num = sqrt(gc);
	while( i <= num ) {
        cout<<"I "<<i<<"\t"<<gc<<endl;
		int vectorCount = 1;
		while(gc%i == 0){
			gc/= i;
			vectorCount += 1;
		}

		if(i == 2)
			i+=1;
		else
			i+=2;
		count*=vectorCount;
		cout<<i<<" "<<vectorCount<<" "<<count<<endl;
	}	
	// for(auto iterator = dictionary.begin(); iterator != dictionary.end(); iterator++){
		// count *= (*iterator + 1);
	// }
    if(gc>1){
        count*=2;
    }
    cout<<count<<endl;
}