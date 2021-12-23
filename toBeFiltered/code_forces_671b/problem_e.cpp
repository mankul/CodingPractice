

#include<iostream>
#include<vector>

using namespace std;


int main()
{
	int t;
	int n;
	for(int i = 0; i<t; i++)
	{
		cin>>n;
		vector<int> divisors;
		for(int i = 2; i<= n; i++)
			if(n%i == 0)
				divisors.push_back(i);
		
		for(int m = 1; m < divisors.size();m++)
		{
			if(divisors[m]-divisors[m-1] == 1)
			{
				int pos = divisors.find(divisors[m]*divisors[n]);
				cout<<pos;
			}
			
		}


	}
	return 0;
}
