

#include<iostream>


using namespace std;


int main()
{
	int m,n;
	cin>>m>>n;
	if(m>n)
	{
		int div = 2;
		for(div = n; div>= 2; div--)
		{
			if(m == 1)
				break;

			if(m%div == 0)
			{
				m=m/div;
				cout<<div<<"\t";
			}
		}
		if( m == 1)
			cout<<"\n m is divisible by n!"<<endl;
		else
			cout<<"not divisible"<<endl;
	}

	else
	{
		cout<<"m is divisible by n!"<<endl;

	}
}

