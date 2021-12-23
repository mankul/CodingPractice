
#include<iostream>
#define NUM 10
#define x1 1
#define x2 2
#define x4 x2, x2
#define x8 x4, x4
#define x16 x8, x8
#define x32 x16, x16
#define x64 x32, x32

using namespace std;

void display(int * array){
	for(int i = 0; i< 10; i++){
	cout<<*(array + i)<<"\t";
	}
	cout<<endl;

}


void add_to_elements(int * array){
	for(int i = 0; i< 10; i++){
		*(array + i) += 20;
	}
}

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	for(int i = 0; i < 10; i++)
	{
		arr[i] += 10;
	}

	display((int *)arr);
	add_to_elements((int *)arr);
	display((int *)arr);
	
	

return 0;
}
