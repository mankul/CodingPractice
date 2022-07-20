


#include<iostream>


using namespace std;

int max( int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int lcs( string X, string Y, int m, int n)
{

	int L[m+1][n+1];
	for(int i = 0; i<= m;i++)
	{
		for(int j = 0;j<=n;j++)
		{
			if( i == 0 || j == 0)
				L[i][j] = 0;
			else
			{
				if(X[i-1] == Y[j-1])
				{
					L[i][j] = 1 + L[i-1][j-1];

				}
				else
				{
					L[i][j] = max(L[i-1][j], L[i][j-1]);
				}
			}
		}
	}
	return L[m][n];
}


int main()
{

	string s1, s2;
	cout<<"enter the two strings"<<endl;
	cin>>s1>>s2;
	int m = s1.size();
	int n = s2.size();
	cout<<lcs(s1,s2,m,n)<<endl;


	return 0;
}
