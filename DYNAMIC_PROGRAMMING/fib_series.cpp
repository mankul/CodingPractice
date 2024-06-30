#include<iostream>
#include<malloc.h>
// not tested yet.
using namespace std;


int  fib(int pos_num, int ** arr, int & arr_populated){
	if(pos_num == 1 or pos_num ==2){
		(*arr)[pos_num] = 1;
		arr_populated = pos_num;
	}
	else if(arr_populated > pos_num)
		return (*arr)[pos_num];
	else if(pos_num == arr_populated){
		(*arr)[pos_num] = (*arr)[arr_populated-2] + (*arr)[arr_populated-1];
		arr_populated += 1;
	}
	else
	{
		int left_fib  = fib(pos_num - 1, arr, arr_populated);
		int right_fib  = fib(pos_num - 2, arr, arr_populated);
		(*arr)[pos_num] = left_fib + right_fib;
	}
	return (*arr)[pos_num];
}

void display_arr(int *arr, int len){
	int index;
	for(index = 0; index < len; index++){
		cout<<arr[index];
	}
}


int main(){
	int **arr;
	int pos_num;
	cin>>pos_num;
	*arr = (int *)malloc(n * sizeof(int));
	int arr_populated = 0;
	int end_pos_num = fib(pos_num, arr, arr_populated);
	return 0;
}
