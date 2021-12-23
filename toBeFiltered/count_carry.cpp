#include<iostream>
#include<string>

using namespace std;

int count_carry(string a, string b)
{

	int carry=0, count=0;
	int sum = 0;
	int len_a = a.length();
	int len_b = b.length();
	int x,y,i=0,j=0;
	
	while( i < len_a || j < len_b)
	{
		if (i < len_a){
			x = a[i] - '0';
			cout<<"x"<<x<<"\t";
			i++;
		}
		if (j < len_b){
			y = b[j] - '0';
			cout<<"y"<<y<<"\t";
			j++;
		}

		sum = x+y+carry;
		if(sum>9)
		{
			carry=1;
			count++;
		}
		else
		{
			carry=0;
		}
		cout<<"carry"<<carry<<endl;
		x=y=sum=0;

	}
	//cout<<a<<b<<endl;
	return count;


}


int main()
{

	string a, b;
	cout<<"enter numbers in form of string"<<endl;
	getline(cin, a);
	getline(cin, b);
	int count = count_carry(a,b);
	cout<<count<<endl;
	return 0;
}
