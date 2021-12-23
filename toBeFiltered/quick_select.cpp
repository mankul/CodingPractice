


#include<iostream>


using namespace std;



void swap(int * arr, int first, int second)
{
	int temp;
	temp = arr[first];
	arr[first] = arr[second];
	arr[second] = temp;
}

int quick_select(int * arr, int st, int end, int k)
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
	if(L == k)
		return L;
	else
	{
		if(L>k)
			return quick_select(arr,i,L-1,k);
		else
			return quick_select(arr,L+1,end,k);
	}
	//if(end>L+1)
	//quick_select(arr,L+1,end);


}



int main()
{

	int num;
	cout<<"enter total numbers:"<<endl;
	cin>>num;
	int k;
	cout<<"enter k value"<<endl;
	cin>>k;
	int arr[num];

	for(auto i = 0; i<num;i++)
	{
		cin>>arr[i];
	}
	int pivot = 0;
	int st=0,end=num-1;
	int number = quick_select(arr,st,end,k);
	cout<<"number is : "<<arr[number]<<endl;


	
	return 0;
}
