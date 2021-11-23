#include<iostream>

template<class T>
bool make2DArray(T ** &arr, int numRows, int * column){
    try{
        arr = new T * [numRows];
        for (int i = 0 ; i < numRows; i++)
            arr[i] = new T [column[i]];
    }
    catch(std::bad_alloc){
        return false;
    }
    return true;
}

template<class T>
void insert_into_array(T ** &arr, int numRows, int * columns){
    for (int i = 0 ; i < numRows; i++)
        for (int j = 0; j < columns[i]; j++)
            arr[i][j] = columns[i];    
    
}

template<class T>
void display(T ** arr, int numRows, int * columns){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < columns[i]; j++)
            std::cout<<arr[i][j]<<"\t";
        std::cout<<std::endl;
    }
}

int main(){
    int ** arr;
    int si[] = {1,2,3,4,5,6,7,8,9,10};
    std::cout<<make2DArray(arr, 10, si)<<std::endl;
    insert_into_array(arr, 10, si);
    display(arr,10, si);

    return 0;
}