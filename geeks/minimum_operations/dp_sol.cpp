#include<iostream>

using namespace std;



int min_op(int num, int & memo){

if(num == 0)
	return 0;
if(num == 1)
	return 1;
if(num == 2)
	return 2;

if (memo[num] != 0)
	return memo[num];

if (num %2 == 0){
	int minm = min(min_op(num-1, memo), min_op(num/2,memo));
	memo[num] = minm+1;
}
else
	memo[num] = min_op(num-1, memo) + 1;

return memo[num];
}



int main(){
int num;
int cases;
cin>>cases;
for(int i = 0; i < cases; i++)
{

cin>>num;
int memo[num];
for(int j = 0; j < num; j++)
	memo[j] = 0;
cout<<min_op(num, memo);

return 0;
}
