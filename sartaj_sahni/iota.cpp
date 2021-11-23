#include<iostream>
template<class T>
void iota(T * arr, int size){
    for(int i = 0; i < size; i++)
        arr[i] += i+1;
}

int main(){
    int a[] = {1,2,3,4,5};
    iota(a, 5);
    for(int i = 0; i < 5; i++)
        std::cout<<a[i]<<std::endl;
    return 0;
}