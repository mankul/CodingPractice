
#include<iostream>


using namespace std;


void merge( int * arr, int st, int mid, int end)
{
	int num = end-st+1;
	cout<<num<<" total"<<endl;
	int newarray[num];
	int i=st ,j= mid+1;
	int count=0;
	while( count < num)
	{
		if(arr[i] < arr[j] && i <= mid)
		{
			newarray[count] = arr[i];
			i++;
			count++;
		}
		else if( i > mid)
		{
			newarray[count] = arr[j];
			j++;
			count++;
		}
		else if(arr[i] >= arr[j] && j <=end)
		{

			newarray[count] = arr[j];
			j++;
			count++;

		}
		else
		{
			newarray[count] = arr[i];
			i++;
			count++;
		}
	}
	for( count=0;count<num;count++)
	{

		arr[st+count] = newarray[count];
		cout<<arr[count]<<"%"<<endl;
	}
}



void divide_and_merge(int * arr,int st, int end)
{
	
	if(!(st == end))
	{
		int mid = (st + end)/2;
		divide_and_merge(arr, st, mid);
		divide_and_merge(arr, mid+1, end);
		merge(arr, st, mid, end);
	}
	

}

void merge_sort(int * arr, int num)
{
	int st, end;
	st = 0;
	end = num-1;

	//cout<<end<<endl;
	int mid = (st + end)/2;
	//cout<<mid<<endl;
	
	divide_and_merge(arr, st, end);
	
	for(int i =0 ; i <num; i++)
	{
		cout<<arr[i]<<endl;
	}
}




int main()

{

	int num;
	cout<<"eneter num f elems"<<endl;
	cin>>num;
	int arr[num];

	for(int i = 0; i<num;i++)
	{
		cin>>arr[i];
	}
	merge_sort(arr, num);
	return 0;
}
