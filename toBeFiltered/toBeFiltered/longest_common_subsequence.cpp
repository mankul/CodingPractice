
#include<iostream>

using namespace std;


int lcs(int *matrix, int num1, int num2, string s1, string s2, int row)
{


	if(num1 < 0 || num2 < 0)
	{
		return 0;

	}
	if(*((matrix + row*num1)+num2) == -1)
	{
	//cout<<*((matrix + row*num1)+num2)<<endl;
		if(s1[num1] == s2[num2])
		{
			{
				cout<<"num1, num2\t"<<num1<<", "<<num2<<"\t"<<s1[num1]<<endl;
				int sum = lcs(matrix, num1-1, num2-1, s1, s2, row);
				*((matrix + row*num1)+num2) = sum + 1;
				return *((matrix + row*num1) + num2);

			}
		}
		else
		{
				int sum1 = lcs(matrix, num1-1, num2, s1, s2, row);
				int sum2 = lcs(matrix, num1, num2-1, s1, s2, row);
				if(sum1 > sum2)
					*((matrix + row*num1)+num2) = sum1;
				else
					*((matrix + row*num1)+num2) = sum2;
				
				return *((matrix + row*num1)+num2);
		}
	}
	else
	{
		return *((matrix + row*num1)+num2);
	}
}


int main()
{



	int num1, num2;
	cout<<"enter  string 1 and string 2 respectively"<<endl;
	string s1, s2;
	cin>>s1>>s2;


	num1 = s1.size();
	num2 = s2.size();
	int matrix[num1][num2];
	for(int i = 0; i<num1;i++)
	{
		for(int j = 0;j<num2;j++)
		{
			matrix[i][j]=-1;
		}
	}
	//for(int i=0;i<num1;i++)
	//	cout<<s1[i]<<endl;
	cout<<num1<<"\t"<<num2<<endl;
	cout<<lcs((int *)matrix, num1-1, num2-1,s1,s2, num2)<<endl;




}
