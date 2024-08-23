#include<iostream>
#include<cmath>

using namespace std;



bool recursiveCall(int num, int factor, int srt_num){
    if( (num % factor == 0) && (factor <= srt_num))
        return false;
    if(factor > srt_num)
        return true;
    return recursiveCall(num, factor+2, srt_num);
 
}


bool isPrimeRecursive(int n){
    if(n<=1)
        return false;
    if(n%2 == 0)
        return false;
    return recursiveCall(n, 3, sqrt(n));
}


bool isPrime(int n){
	if(n<=1)
		return false;
	if(n%2 == 0)
		return false;
	for(int i = 3; i < sqrt(n); i++)
		if(n%i == 0)
			return false;
	return true;


}


int main(){
    int num;
    std::cin>>num;
    bool res = isPrime(num);
    std::cout<<"Iterative Call Solution"<<std::endl;
    std::cout<<(res?"Prime Number":"Not Prime")<<std::endl;
    res = isPrimeRecursive(num);
    std::cout<<"Recursive Call Solution"<<std::endl;
    std::cout<<(res?"Prime Number":"Not Prime")<<std::endl;
    return 0;
}
