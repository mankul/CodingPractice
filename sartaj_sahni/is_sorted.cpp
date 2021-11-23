#include<iostream>

template<class T>
bool is_sorted(T * arr, int size){
    bool sorted = true;
    for(int i = 0; i < size-1; i++)
        if (arr[i] > arr[i+1]){
            sorted = false;
            break;
        }
    return sorted;
}

int main(){
    int a[] = {1,2,3,4};
    int b[] = {1,3,2,4};
    std::cout<<is_sorted(a, 4)<<std::endl;
    std::cout<<is_sorted(b, 4)<<std::endl;
    return 0;
}