#include<iostream>


using namespace std;


int main()
{
	int s = 42;
	int j =3;
	int l;
	int t = 8;
	int m,n,k;
	k = s ^ (1 <<j);
	n = s & ~(1 <<j);
       	m = s & (1<<j);
	cout<<m<<"\t"<<n<<"\t"<<k<<endl;
	return 0;
}
