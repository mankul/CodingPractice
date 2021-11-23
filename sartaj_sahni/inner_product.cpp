#include<iostream>

template<class T>
void inner_product(T * a, T * b, int n){
    for(int i = 0; i < n; i++)
        a[i] = a[i] * b[i];
}

int main(){
    int size = 10;
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    int b[] = {1,2,3,4,5,6,7,8,9,10};
    inner_product(a,b,size);
    for(int i = 0; i < size; i++)
        std::cout<<a[i]<<std::endl;
    return 0;
}