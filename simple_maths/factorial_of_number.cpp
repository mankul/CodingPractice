#include<iostream>


using namespace std;

long int factorial(int number){

	if(number == 0 || number == 1)
		return 1;

	return number * factorial(number-1);

}



int main()
{
int test_cases, number;
cin>>test_cases;

for(int i = 0; i< test_cases; i++)
{
	cin>>number;
	cout<<factorial(number)<<endl;
}

return 0;
}
