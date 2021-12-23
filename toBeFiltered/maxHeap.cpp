#include<iostream>


using namespace std;


struct node {


	int value;
	node * left;
	node * right;

};


void heapify( int * arr, int num)
{
	if(num == 0)
		return;
	if(num%2 == 1)
	{
		if( arr[num] > arr[(num-1)/2])
		{
			// compare with num-1/2
		 	int temp = arr[num];
			arr[num]=arr[(num-1)/2];
			arr[(num-1)/2] = temp;
			heapify(arr,(num-1)/2);

		}
	}
	else
		if( arr[num] > arr[num/2-1])
		{
			// compare with num-2/2
			int temp = arr[num];
			arr[num] = arr[num/2-1];
			arr[num/2-1]  = temp;
			heapify(arr,num/2-1);
		}
}


void adjust_heap(int * num_arr, int heap_size, int index)
{
	if(heap_size == 0)
		return;
	int left_index = 2*index + 1;
	int right_index = 2*index + 2;
	if(left_index < heap_size)
	{	if( right_index <= heap_size)
		{

			int temp1, temp2;
			temp1 = num_arr[left_index];
			temp2 = num_arr[right_index];
			if(temp1>temp2)
			{
				if(num_arr[index] < temp1)
				{
					int temp = num_arr[left_index];
					num_arr[left_index] = num_arr[index];
					num_arr[index] = num_arr[left_index];
					adjust_heap(num_arr,heap_size, left_index);
				}
			}
			else
			{
				if(num_arr[index] < temp2)
				{
					int temp = num_arr[right_index];
					num_arr[right_index] = num_arr[index];
					num_arr[index] = num_arr[right_index];
					adjust_heap(num_arr,heap_size, right_index);
					
				}

			}
		}
		else
		{

			if( num_arr[index]< num_arr[left_index])
			{
				int temp = num_arr[left_index];
				num_arr[left_index] = num_arr[index];
				num_arr[index] = num_arr[left_index];
				adjust_heap(num_arr, heap_size, left_index);
			}
		}
	}
}



void max_heap_sort(int * arr, int num)
{
	int num_arr[num];
	for(int i =0;i<num;i++)
	{
		num_arr[i]=arr[i];
	}
	int heap_size = num-1;
	for(int i =0;i<num;i++)
	{
		arr[i]=num_arr[0];

		int temp = num_arr[heap_size];
		num_arr[heap_size] = num_arr[0];
		num_arr[0]=temp;
		heap_size--;
		adjust_heap(num_arr,heap_size, 0);
	}

}
int main()
{



	int num;
	cout<<"enter elements in array"<<endl;
	cin>>num;

	int arr[num];
	int new_arr[num];
	cout<<"enter numbers"<<endl;
	for(int i = 0; i <num; i++)
	{
		cin>>arr[i];
	}
	
	int loop_count = num/2;

	
	for(int i =0; i< num; i++)
	{
		new_arr[i]=arr[i];
		heapify(arr,i);
	}

	//max_heap_sort(arr, num);
	
	for(int i = 0; i <num; i++)
	{
		cout<<arr[i]<<endl;
	}
	return 0;
}
