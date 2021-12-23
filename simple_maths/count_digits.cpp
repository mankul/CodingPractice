

#include<iostream>
#include<vector>

using namespace std;

int main()
{

	int test_cases, number;
	cin>>test_cases;
	for(int i = 0;i < test_cases; i++)
	{
		int digit;
		cin>>number;
		vector<int> digits;
		if(number == 0)
			digits.push_back(0);
		else{
			while(number>0)
			{	
				digit = number % 10;
				number /= 10;
				digits.push_back(digit);
			}
		}	
		for(vector<int>::iterator i = digits.begin();i != digits.end(); i++)
		{
			cout<<*i<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
