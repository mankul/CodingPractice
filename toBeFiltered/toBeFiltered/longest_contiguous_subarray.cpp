#include<iostream>


using namespace std;

int main()
{

	int arr[] = {1,2,3,2,3,4,5,3,1,2,5,6,78,966,54,44,-1,-20,1,1,3,4,5,333,4};
	int n = sizeof(arr)/sizeof(int);
	int length=1;
	int longest_length=1;
	for(int i = 1; i <n; i++)
	{
		if(arr[i]>=arr[i-1])
			length++;
		else
		{
			if(length>longest_length)
				longest_length=length;
			else
				length=1;

		}

	}
	cout<<longest_length<<endl;	
}
