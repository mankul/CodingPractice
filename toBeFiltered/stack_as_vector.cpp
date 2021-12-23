#include<iostream>
#include<vector>

using namespace std;
void stack(vector<int> & stack, int n)
{

	// remove the elements from the stack top
	for(int i = 0; i< n; i++)
	{
		cout<<stack.front()<<"\t";
		cout<<stack.back()<<endl;
		stack.pop_back();
	}
       
}


int main()
{


	vector<int> stack{};

	int arr[] = {1,3,2,55,33,25,555,443,657,8769};
	int n = sizeof(arr)/sizeof(int);
	// insert into the vector at the begining for queue operation
	for(int i = 0; i< n;i++)
	{
		stack.insert(stack.begin(),arr[i]);
		stack.resize(i+1);
		
	}
	// pop from the end for FIFO operation.
	for(int i = 0; i< n; i++)
	{
		cout<<stack.back()<<endl;
		stack.pop_back();
	}
       
	return 0;
}
