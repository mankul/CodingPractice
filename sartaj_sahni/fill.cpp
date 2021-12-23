#include<iostream>

template<class T>
void fill(T * arr, int size, T value){
    for(int i = 0; i < size ; i++)
        arr[i] = value;
}

int main(){
    int arr[10];
    int val = 10;
    fill(arr, 10, val);
    for(int i = 0; i < 10; i++)
        std::cout<<i<<"\t"<<arr[i]<<std::endl;
    return 0;
}