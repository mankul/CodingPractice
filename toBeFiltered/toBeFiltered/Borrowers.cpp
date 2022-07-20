#include<iostream>
#include<vector>

using namespace std;


int main()

{
	string st;
	int endcount=0;
	vector<pair<string,string>> library;
	string delimeter = "by";
	string book_name, author_name;
	while(getline(cin,st))
	{

		if(st == "END" && endcount == 1)
			break;
		else if(st == "END")
			endcount++;
		if(endcount==0)
		{
			int pos = st.find(delimeter);
			int start = 0U;
			book_name = st.substr(start,pos-start);
			start = pos + delimeter.length();
			author_name = st.substr(start, st.length()-start);
			cout<<book_name<<"\t"<<author_name<<endl;
		}
		else
		cout<<st<<endl;
	}
}
