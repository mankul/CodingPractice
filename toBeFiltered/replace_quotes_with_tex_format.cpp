

#include<iostream>

using namespace std;


int main()

{
	string s;
	string new_s="";
	getline(cin,s);
	int size = s.size();
	bool c=false;
	for(int i = 0; i< size; i++)
	{
		if(s[i] == '\"' && c ==false)
		{

			c=true;
			new_s=new_s + "\\{";

		}
		else if(s[i] == '\"' && c == true)
		{
			new_s = new_s+"}";
			c=false;
		}
		else
			new_s=new_s+s[i];

	}
	cout<<new_s<<endl;


	return 0;
}
