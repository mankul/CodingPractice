#include<iostream>

// not tested yet.
using namespace std;


int  fib(int num, int ** arr, int & len){
	if num == 1 or num ==2:
		*arr[num] = 1;
		len = num;
		return 1;
	if len > num
		return *arr[num];
	if num == len 
		arr[num] = arr[len-2] + arr[len-1];
		len += 1;
		return *arr[num];
	else
		int num1  = fib(num - 1, arr, len);
		int num2 = fib(num - 2, arr, len)
		return num1 + num2;
}


int main(){
	int *arr;

	return 0;
}
