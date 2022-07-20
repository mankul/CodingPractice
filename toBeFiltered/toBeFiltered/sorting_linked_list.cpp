#include<iostream>
#include<vector>

using namespace std;


struct node{

	node * next;
	int value;
};

int main()
{
	int num;
	cout<<"enter number of nodes"<<endl;
	cin>>num;
	vector<int> arr(num);
	node * head;
	node * ptr;
	cout<<"enter elements to be inserted to linked list"<<endl;
	for(auto i=0; i< num;i++)
	{
		cin>>arr[i];
		if(head == NULL)
		{
			head = new node();
			head->value = arr[i];
			head->next = NULL;
			ptr = head;
		}
		else
		{
			node * temp = new node();
			
			if ( temp->next == NULL)
				cout<<"temp"<<endl;
			ptr->next = temp;
			ptr = ptr->next;

		}
		
	}

	
	
	return 0;
}
