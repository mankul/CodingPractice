

#include<iostream>


using namespace std;


int main()
{
	int n;
	int t=20;
	int cycle_count=100;
	while(t>0)
	{
		int counter=0;
		cin>>n;
		while(n!=1)
		{
			if(n%2 != 0)
				n=3*n+1;
			else
				n=n/2;
			cout<<n<<"\t";
		}
		cout<<endl;
		t--;
		//cout<<"\n\n\n"<<t<<"\n\n\n";
		counter++;
		if(counter>cycle_count)
			break;
	}
}
