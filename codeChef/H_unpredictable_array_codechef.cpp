

#include<iostream>
#include<vector>

using namespace std;


int mod_sub(int a, int b)
{
	return a>b? a-b:b-a;
}

int main()
{
	int n,q, t;
	cin>>t;
	for(int c = 0; c< t; c++){
		cin>>n>>q;
		vector<int> array;
		int number, replacement;

		for(int i = 0; i < n; i++)
		{
			cin>>number;
			array.push_back(number);
		}
		int num_arr[q];
		int replace_arr[q];
		for(int i = 0; i < q; i++){
			cin>>num_arr[i]>>replace_arr[i];
		}
		cout<<"Case "<<c<<":"<<endl;
		for(int i = 0; i < q; i++){
			int sum = 0;
			number=num_arr[i];
			replacement=replace_arr[i];
			for(int j = 0; j < n-1; j++){
				if(array[j] == number){
					array[j] = replacement;
				}
				if(array[j+1] == number){
					array[j+1] = replacement;
				}
				sum+=mod_sub(array[j], array[j+1]);
				
			}
			cout<<sum<<endl;

			// for(int j = 0;j< n; j++)
			// cout<<array[j];
			// cout<<endl;

		}
	}

}
