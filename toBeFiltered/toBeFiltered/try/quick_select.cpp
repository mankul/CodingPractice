

#include<iostream>
#include<vector>

using namespace std;

int quick_select(vector<int> arr, int st, int en, int num)
{

	if(st == en)
	{
		if( num != arr[st])
			return -1;
		else
			return st;
	}
	int L = st, temp;
	for( int i = st; i<= en; i++)
	{
		if(num == arr[i])
		{

			return i;
			
		}
		if(arr[i] < arr[st])
		{
			L++;
			temp = arr[i];
			arr[i]  = arr[L];
			arr[L] = temp;
		}
	}
	temp = arr[st];
	arr[st] = arr[L];
	arr[L] = temp;
	if( num > arr[L])
		return quick_select(arr, L+1, en, num);
	else
		return quick_select(arr, st, L-1, num);
}

int main()

{


	// quick select
	//
	//

	int i, j;
	int num;
	cin>>num;
	vector<int> arr(num);

	for( i =0;i<num;i++)
	{
		cin>>arr[i];
	}
	int number;
	cin>>number;

	cout<<quick_select(arr,0, num-1, number)<<endl;
	return 0;
}
