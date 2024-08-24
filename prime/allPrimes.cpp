#include<iostream>
#include<map>
#include<vector>
#include<cmath>
//using namespace std;


// Aim: is to identify all the prime numbers below the given number
// Algo: To find all the numbers, let us grow loop with 2 increment. If the number is a prime, it shall not be divisible
// by all the prime numbers smaller than itself. Hence using a dynamic array to store all prime numbers. The numbers
// will be stored in ascending order itself. 
// Is there any better way to increment the loop? This increment is making finding the algorithm very slow."
// Complexity: 
// Time: for every test case, finding the primes with 2 step incr. Therefore O(n)
// space: Depends upon the count of primes smaller than given number . \theta(logn). Need to verify.

void allPrimes(int num, std::vector<int> & arr){
    int counter = 2;
    bool prime_flag;
    if(counter <= num)
        arr.push_back(counter);
    counter += 1;
    while(counter <= num){
        prime_flag = true;
        for(auto iter = arr.begin(); iter != arr.end(); iter++){
            if(counter % *iter == 0){
                prime_flag = false;
                break;
                }
        }
        if(prime_flag == true)
            arr.push_back(counter);
        counter += 2;
    }
}

int main(){
	int test_cases;
    int number;
    std::cout<<"Enter test cases count"<<std::endl;
    std::cin>>test_cases;
    for(int t = 0; t< test_cases; t++){
        std::cout<<"Enter the max number until which all primes have to be listed."<<std::endl;
        std::cin>>number;
        std::vector<int> prime_numbers_arr;
        allPrimes(number, prime_numbers_arr);   
        for(auto iter = prime_numbers_arr.begin(); iter != prime_numbers_arr.end(); iter++){
            std::cout<<*iter<<"\t";
        }
        std::cout<<std::endl;
}


return 0;
}
