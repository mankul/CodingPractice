#include<iostream>


using namespace std;




long int fib(long int * fibonac, int num)
{
	if(num == 0 || num == 1)
	{
		fibonac[num]=1;
		return 1;
	}
	else
	{
		if(fibonac[num]==-1)
		{
			long sum1 = fib(fibonac, num-1);
			long sum2 = fib(fibonac, num-2);
			fibonac[num] = sum1 + sum2;
			return fibonac[num];
		}
		else
		{
			return fibonac[num];
		}
	}
}


int main()

{


	int num;
	cout<<"enter the number for fibonacci calculation"<<endl;
	cin>>num;

	long int fibonac[num];
	for(int i = 0; i<= num; i++)
		fibonac[i]=-1;
	cout<<fib(fibonac,num)<<endl;
	return 0;
}
