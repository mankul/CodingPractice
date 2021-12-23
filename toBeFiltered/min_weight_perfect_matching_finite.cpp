#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
	cout<<"enter number of pairs."<<endl;
	int p;
	cin>>p;
	int x,y;
	int num = 2 * p;
	vii coordinate_arr(num);
	cout<<"enter coordinate of "<<num<<"  students as (x,y)"<<endl;
	for(int i =0; i<num; i++)
	{
		cin>>x>>y;
		ii coordinate = make_pair(x,y);
		coordinate_arr[i] = coordinate;
	}
	cout<<"coordinates are"<<endl;
	for(int i =0; i< num; i++)
	{
		cout<<coordinate_arr[i].first<<"\t"<<coordinate_arr[i].second<<endl;
	}

	
	return 0;

}

