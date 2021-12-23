
#include<iostream>
#include<vector>

using namespace std;

int binary_search( vector<int> array, int left, int right, int element)
{
	if(element == array[left])
	{
		return left;

	}
	if(element == array[right])
	{

		return right;
	}
	if(left == right)
	{
		if(array[left] == element)
		{
			return left;
		}
		else
		{
			return -1;
		}

	}

	int mid = (left + right)/2;
	if(mid == left)
	{
		return -1;
	}

	if(element > array[left] && element < array[mid])
	{
		return binary_search(array, left, mid , element);
	}
	else
	{
		return binary_search(array, mid, right, element);
	}


}


int binary_search(vector<int> array, int size, int element)
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

int main()

{

	int programIterationOverflow=0;
	int thresholdOverflow = 100;
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

	int wantToRepeat = 1;
	while(wantToRepeat)
	{
		cout<<"enter element to be found"<<endl;
		int element;
		cin>>element;
		int answer = binary_search(array, size, element);
		if(answer == -1)
		{
			cout<<"element not found"<<endl;
		}
		else{
			cout<<"element is "<<element<<" at index "<<answer<<endl;
		}
		cout<<"Doesnt want to repeat , enter 0"<<endl;
		cin>>wantToRepeat;
		programIterationOverflow++;
		if (programIterationOverflow > thresholdOverflow)
			break;
	}
	return 0;
}


