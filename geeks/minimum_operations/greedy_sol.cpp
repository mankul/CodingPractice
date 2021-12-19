#include<iostream>


using namespace std;


int main(){

int cases;
cin>>cases;
int num;
for(int i =  0; i < cases; i++)
{
	cin>>num;
	int count = 0;
	while(num > 2){
		if (num % 2 == 0)
			num/=2;
		else
			num-=1;
		count+=1;
	}
	if(num == 2)
		count+=2;
	else if(num == 1)
		count+=1;
	cout<<"minimum operations are "<<count<<endl;
}

return 0;
}
