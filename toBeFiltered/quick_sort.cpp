


#include<iostream>


using namespace std;



void swap(int * arr, int first, int second)
{
	int temp;
	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

void quick_sort(int * arr, int st, int end)
{

	int i=st;
	int j=end;
	int L=i;
	
	for(int R = i+1 ; R<=j ; R++)
	{
		if(arr[i]>arr[R])
		{
			L++;
			swap(arr,L,R);
		}	
	}
	swap(arr,L,i);
	if(L>i)
	quick_sort(arr,i,L-1);
	if(end>L+1)
	quick_sort(arr,L+1,end);


}



int main()
{

	int num;
	cout<<"enter total numbers:"<<endl;
	cin>>num;
	int arr[num];

	for(auto i = 0; i<num;i++)
	{
		cin>>arr[i];
	}
	int pivot = 0;
	int st=0,end=num-1;
	quick_sort(arr,st,end);
	for(auto i = 0; i<num;i++)
	{
		cout<<arr[i]<<endl;
	}


	
	return 0;
}
