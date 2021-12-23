#include<iostream>


using namespace std;


int counting_bst( int * count_bst,  int iter)
{
	if(iter == 0 || iter == 1)
	{
		count_bst[iter] = 1;
		return 1;
	}
	else if(iter == 2)
	{
		count_bst[iter]=2;
		return 2;
	}

	if(count_bst[iter] == -1)
	{
		int total1 = 0;

		for(int i = 0; i < iter ; i++)
		{
			int num1 = counting_bst( count_bst,  i);
			int num2 = counting_bst( count_bst,  iter -1 -i);
			total1+= (num1 * num2);
		}
		count_bst[iter] = total1;
		return total1;
	}
	else
	{
		return count_bst[iter];
	}
}

int main()

{
	cout<<"enter number of elements in inorder of bst"<<endl;
	int num;
	cin>>num;
	int count_bst[num];

	for(int i = 0; i <= num; i++)
	{
		count_bst[i]=-1;
	}
	int total;
       	total = counting_bst(count_bst, num);
	cout<<total<<endl;
	return 0;
}
