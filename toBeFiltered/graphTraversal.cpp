
#include<iostream>
#include<vector>

using namespace std;


int linear_search(vector<int> array, int size, int element)
{
	cout<<"linear search"<<endl;
	for(auto i=0;i<size;i++)
	{
		if (array[i] == element)
		{
			return i;
		}

	}
	return -1;
}
void linear_search(vector<int> array, int size)
{
	cout<<"linear search"<<endl;
	for(auto i=0;i<size;i++)
	{
		cout<<array[i]<<endl;
	}
}

int main()

{


	cout<<"enter size of array"<<endl;
	int size;
	cin>>size;
	cout<<"enter array elements with spaces"<<endl;
	vector<int> array(size);
	int i;
	for(i=0;i<size;i++)
	{

		cin>>array[i];
	}
	
	for(i=0;i<size;i++)
	{
		cout<<array[i]<<endl;
	}

	cout<<"enter element to be found"<<endl;
	int element;
	cin>>element;
	int answer = linear_search(array, size, element);
	if(answer == -1)
	{
		cout<<"element not found"<<endl;
	}
	else{
		cout<<"element is "<<element<<" at index "<<answer<<endl;
	}
	return 0;
}


