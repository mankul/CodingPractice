#include<iostream>
#include<vector>

using namespace std;



void palindrome_function(int number)
{
	vector<int> digits;

	if(number == 0)
	{
		cout<<"Palindrome"<<endl;
		return;
	}
	int count=0;
	while(number>0)
	{
		int digit = number%10;
		number=number/10;
		digits.push_back(digit);
		count++;
	}
	for(int i = 0; i < count/2; i++)
	{
		if(digits[i] != digits[count-1-i])
		{
			cout<<"Not a Palindrome"<<endl;
			return;
		}
	}
	cout<<"Palindrome"<<endl;
}


int main()
{


int test_case, number;

cin>>test_case;

for(int i = 0; i< test_case; i++)
{
	cin>>number;
	palindrome_function(number);
}


return 0;
}



