#include<iostream>
#include<vector>

using namespace std;

#define BUDGET_UNIT long long


void swap(BUDGET_UNIT &a, BUDGET_UNIT &b){
	BUDGET_UNIT temp = a;
	a = b;
	b = temp;
}


void quickSort(vector<BUDGET_UNIT> & arr, int left, int right){
	if(left >= right)
		return;
	else{
		int pivot = (left + right)/2;
		swap(arr[pivot], arr[right]);
		int i , j;
		for( i = left, j = left; i < right; i++){
			if(arr[right] <= arr[i]){// decreasing order -> arr[pivot] >= arr[i] increaing order
				swap(arr[i], arr[j]);
				j += 1;
			}
		}
		swap(arr[right], arr[j]);
		quickSort(arr, left, j-1);
		quickSort(arr, j + 1 , right);
	}
}


long long maximumProfit(vector<BUDGET_UNIT> & arr){
	// quick sort
	int length = arr.size();
	// cout<<"length"<<length<<endl;
	quickSort(arr, 0 , length-1);
	BUDGET_UNIT maximum = 0;
	for(int i = 0; i < length ; i++){
		if(maximum < (i+1) * arr[i]){
			maximum = (i+1)*arr[i];
		}
		// cout<<arr[i]<<endl;
	}
	return maximum;
}


int main(){
	int nums;
	cin>>nums;
	BUDGET_UNIT budget;
	vector<BUDGET_UNIT> arr;
	for(int i = 0; i < nums; i++)
	{
		cin>>budget;
		arr.push_back(budget);
	}

	cout<<maximumProfit(arr)<<endl;

	return 0;
}
