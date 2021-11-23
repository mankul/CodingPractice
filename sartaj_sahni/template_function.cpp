#include<iostream>
#include<vector>

template <class T>
int count(std::vector<T> arr){
    int counting=0;
    for(auto iterator = arr.begin(); iterator != arr.end(); iterator++){
        counting++;
        std::cout<<*iterator;
    }
    return counting;
}



int main(){
    int size;
    std::vector<int> arr ;
    arr = {1,2,3,4,5};
    std::cout<<count(arr)<<std::endl;
    return 0;
}