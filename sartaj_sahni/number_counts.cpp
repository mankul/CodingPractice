#include<iostream>


template<class T>
int count(T * arr, int size, T value){
    if (size < 1)
        throw "Array size is < 1";
    int counting = 0;
    for(int i = 0 ; i< size; i++){
        if (arr[i] == value)
            counting++;
    }
    return counting;
}

int main(){
    int val = 2;
    int arr[] = {1, 2 , 2, 4, 5};
    try{
        std::cout<<count(arr, 0, 2)<<std::endl;
    }
    catch(const char * e){
        std::cout<<e<<std::endl;
    }
    return 0;
}