// dynamic programming problem
//
//
//
//
// longest common subsequence
#include<iostream>

using namespace std;


int max( int a, int b)
{
	if ( a>b)
		return a;
	else
		return b;
}

int longest_common_subsequence( string s1, string s2)
{


	int l1 = s1.size();
	int l2 = s2.size();

	int mat[l1+1][l2+1];

	for( int i = 0; i <= l1; i++)
	{
		for(int j = 0; j<= l2; j++)
			mat[i][j] = -1;
	}
	for(int i = 0; i<= l1; i++)
	{
		for( int  j= 0;j<= l2; j++)
		{
			if(s1[i-1] == s2[j-1])
			{
				mat[i][j] = mat[i-1][j-1] + 1;
			}
			else
			{
				mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
			}
		}
		
	}
	return mat[l1][l2];
}


int main()
{

	string s1,s2;
	cout<<"enter string 1 and 2 respectivel"<<endl;


	cin>>s1>>s2;

	cout<<longest_common_subsequence(s1,s2)<<endl;


	return 0;
}
