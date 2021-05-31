

#include<iostream>


using namespace std;

int main()
{

int len = sizeof(int) * 8;
int num = 3000000000;
for(int i = 0; i < len; i++)
{
	if ( ((1<<i) & num) != 0)
		cout<<i<<"\t"<<(1<<i)<<endl;
}

return 0;
}
