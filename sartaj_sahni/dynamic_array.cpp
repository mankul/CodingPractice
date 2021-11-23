#include<iostream>


#define columns 10

template<class T>
bool make2DArray(T ** & arr, int numRows, int numCols){
    
    try{
        arr = new T * [numRows];

        for (int i = 0; i < numRows; i++){
            arr[i] = new T [numCols];
        }
    }catch(std::bad_alloc){
        return false;
    }

    return true;
}

template<class T>
void insert_values(T ** &arr, int numRows, int numCols){
    for(int i = 0; i < numRows; i++)
        for(int j = 0; j < numCols; j++)
            arr[i][j] = 1;
}


int main(){
    int n,m;
    std::cin>>n>>m;

    char ** arr;
    std::cout<<make2DArray(arr, m, n)<<std::endl;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            std::cout<<arr[i][j]<<std::endl;

    // char (* arr) [columns] ;
    // try{
    //     arr = new char[n][columns];
    // }
    // catch(std::bad_alloc){
    //     std::cout<<"error in allocating memory"<<std::endl;
    //     exit(1);
    // }
    return 0;
}