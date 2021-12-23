#include<iostream>


using namespace std;


int main()
{
	int t;
	//cin>>t;
	//for(int t1 = 0; t1<t ;t1++){
		int n;
		cin>>n;
		string st;
		int space[n];
		int min=26;
		for(int i = 0; i<n;i++)
		{
			getline(cin,st);
			int spaces = 0;
			for(int j = 0; j < st.length();j++)
			{
				if(st[j] == 'B')
					spaces++;
			}
			space[i]=spaces;
			if(spaces<min)
				min=spaces;
		}
		int total = 0;
		for(int i = 0; i < n ; i++)
			total+=space[i];
		total-=(n*min);
		cout<<endl;
		cout<<total<<endl;
	//}
	return 0;
}
