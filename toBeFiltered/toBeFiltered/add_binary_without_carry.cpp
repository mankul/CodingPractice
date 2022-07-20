#include<iostream>
#include<bits/stdc++.h>


using namespace std;

int xor_sum(int num_1, int num_2)
{

	int sum;
	
	sum = num_1 + num_2;
	return sum;
}

string convert_to_binary_string(int num){
	int n = num ;
	string s1;
	int carry;
	while(n!=0)
	{
		n = n/2;
		carry = num %2;
		s1 = to_string(carry) + s1;
		cout<<s1<<endl;
	}

}
int main()
{
	int num1, num2;
	cin>>num1>>num2;
	string s1 = convert_to_binary_string(num1);
	string s2 = convert_to_binary_string(num2);

	int sum = xor_sum(num1, num2);
	cout<<sum<<endl;
	return 0;
}
