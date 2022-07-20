

#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<bool> prime(n+1, true);

	prime[0] = prime[1] = false;
	for(int i = 0; i <= n ; i++)
	{
		if( prime[i] && (long long) i*i <=n)
		{
			for(int j = i*i;j<=n;j+=i)
			{
				if(j%i == 0)
					prime[j] = false;
			}
		}
	}

	for(int i = 0; i<= n; i++)
		if(prime[i])
			cout<<i<<"\t";
	cout<<endl;
	return 0;
}
