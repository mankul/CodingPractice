#include<iostream>

using namespace std;

int main () {
	


	int t;
	cin>>t;
	string password;
	for(int i = 0; i< t; i++)
		cin>>password;
	int password_length = password.length();
	bool len_cond = false;
	bool num_cond = false;
	bool small_alph = false;
	bool capital = false;
	bool special_chars = false;
	if(password_length >= 7)
		len_cond = true;

	for(int i = 0; i < password_length; i ++)
	{
		if( password[i] - 'a' <= 26)
			small_alph = true;
		if(password[i] - 'A' <= 26)
			capital = true;
		if(password[i] - '0' <= 9)
			num_cond = true;
		special_chars = password[i] == '#' ? true : password[i] == '@' ? true: password[i] == '*' ? true : password[i] == '&' ? true : false;
	}

	string newPassword=password;
	if(!num_cond)
		newPassword += '1';
	if(!small_alph)
			newPassword += 'a';
	if(capital)
		newPassword += 'A';
	if(special_chars)
		newPassword += '#';
	
	if(!len_cond)
	{	
		int length = newPassword.length();
		for(int i = length; i < 7 ; i ++)
			newPassword += '1';
	}

	cout<<newPassword<<endl;
	return 0;


}


