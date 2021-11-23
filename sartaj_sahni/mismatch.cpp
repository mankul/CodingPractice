#include<iostream>
template<class T>
int mismatch(T * a, T * b, int size){
    for(int i = 0; i< size; i++)
        if(a[i] != b[i])
            return i;
    return size-1;
}

int main(){
    int a[] = {1,2,3,4};
    int b[] = {1,2,3,4};
    int c[] = {1,2,2,4};
    float d[] = {1.0,2.0,3.0};
    float e[] = {1, 2, 3};
    std::cout<<mismatch(a,b,4)<<std::endl;
    std::cout<<mismatch(a,c,4)<<std::endl;
    std::cout<<mismatch(d,e,3)<<std::endl;

    return 0;
}