#include<iostream>


template<class T>
void change_length(T * oldArr, T * &newArr, int oldLen, int newLen){
    newArr = new T [newLen];
    for(int i = 0; i < oldLen; i++){
        if (i == newLen)
            break;
        newArr[i] = oldArr[i];
    }
}

void display_array(int * arr, int len){
    for(int i = 0; i < len; i++)
        std::cout<<arr[i]<<"\t";
    std::cout<<std::endl;
}

int main(){

    int arr[] = {1,2,3,4,5};
    int oldLen = 5;
    int newLen = 7;
    int * oldArr;
    int * newArr;
    oldArr = new int [5];
    oldArr = arr;
    display_array(oldArr, 5);
    change_length(oldArr, newArr, oldLen, newLen);
    display_array(newArr, 5);
    

    return 0;
}