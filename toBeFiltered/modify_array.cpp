

#include<iostream>


using namespace std;

void alter_array( int * arr, int num)
{
	for(int i = 0; i< num;i++)
	{
		arr[i] = arr[i] + 5;
	}
}


int main()
{

	int arr[] = {1,2,3,4,5};
	for(int i =0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	}
	alter_array(arr,5);
	for(int i =0;i<5;i++)
	{
		cout<<arr[i]<<endl;
	}

	return 0;
}
