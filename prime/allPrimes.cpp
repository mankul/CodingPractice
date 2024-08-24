#include<iostream>
#include<map>
#include<vector>
#include<cmath>
//using namespace std;


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
