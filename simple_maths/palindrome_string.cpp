

#include<iostream>


using namespace std;

void palindrome_string(string name)
{
	// sizeof gives the size of the variable
	int length;
	length = name.length();
	for( int i = 0; i< length/2; i++)
	{
		if(name[i] != name[length-1-i])
		{
			cout<<"Not a Palindrome String"<<endl;
			return;
		}
	}
	cout<<"Palindrome String"<<endl;


}

int main()
{

	int test_cases;
	string name;
	cin>>test_cases;

	for(int i = 0; i< test_cases; i++)
	{
		cin>>name;
		palindrome_string(name);
	}

return 0;
}
