#include<iostream>
#include<malloc.h>
// not tested yet.
using namespace std;


int  fib(int pos_num, int ** arr){
	if(pos_num == 1 or pos_num ==2){
		(*arr)[pos_num] = 1;
	}
	else if( (*arr)[pos_num] == -1){
		int left_fib  = fib(pos_num - 1, arr);
		int right_fib  = fib(pos_num - 2, arr);
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

void initialize_arr(int ** arr, int len){
	for(int i = 0; i < len; i++)
		(*arr)[i] = -1;
}

int main(){
	int **arr;
	int pos_num;
	cin>>pos_num;
	*arr = (int *)malloc(pos_num * sizeof(int));
	initialize_arr(arr, pos_num);
	int end_pos_num = fib(pos_num, arr);
	return 0;
}
