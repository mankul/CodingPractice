#include<iostream>


using namespace std;

void swap(int & i, int & j)
{
	int temp = i;
	i = j;
	j = temp;
}

int main()
{
	int arr[] = {1,2,3,2,3,4,5,3,1,2,5,6,78,966,54,44,-1,-20,1,1,3,4,5,333,4};
	int n = sizeof(arr)/sizeof(int);
	for(int i = 1; i< n; i++)
		for(int j=i-1 ; j>=0;j--)
		{	if(arr[j]<=arr[j+1])
			{
				//swap(arr[i],arr[j+1]);
				break;
			}
			else
			{
				swap(arr[j],arr[j+1]);
			}

		}
	int counter=1;
	int prev=arr[0];
	for(int i = 1; i < n;i ++)
	{

		if(arr[i] == prev)
		{
			counter++;
		}
		else
		{
			if(counter>1)
			{
				if(counter%2 == 0)
					cout<<"even("<<counter<<")\t";
				else
					cout<<"odd("<<counter<<")\t";
				cout<<prev<<endl;
			}
			prev = arr[i];
			counter=1;
		}


	}
	int number;
	cin>>number;
	int i,j;
	for(i = 0, j = n; i< n, j>=0; )
	{
		if(arr[i] + arr[j] > number)j--;
		else if(arr[i] + arr[j] < number)i++;
		else{cout<<arr[i]<<"\t"<<arr[j]<<endl;break;}
	}
	return 0;
}
