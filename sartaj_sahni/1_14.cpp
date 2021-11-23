#include<iostream>

#define row 3
#define col 3
#define newRow 4
#define newCol 4


template<class T>
void change2DDimension(T ** oldArr, T ** & newArr, int oldRow, int oldCol, int newRows, int newCols){
    newArr = new T * [newRows];
    for(int i = 0; i< newRows; i++)
        newArr[i] = new T[newCols];
    for(int i = 0; i < oldRow ; i++){
        if(i == newRows)
            break;
        for(int j = 0; j < oldCol; j++)
        {
            if( j == newCols)
                break;
            newArr[i][j] = oldArr[i][j];
        }
    }

    try{
        for(int i = 0; i< oldRow; i++)
            delete [] oldArr[i];
    }
    catch(std::bad_alloc){
        std::cout<<"bad memory";
    }

}

template<class T>
void display2DArray(T ** arr, int rows, int cols){
    for(int i = 0; i < rows ; i ++){
        for(int j = 0 ; j < cols ; j++)
            std::cout<<arr[i][j]<<"\t";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

int main(){
    // int row = 3;
    // int col = 3;
    int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int ** oldArr;
    int ** newArr;
    oldArr = new int * [row];
    for(int i = 0; i < row; i++)
        oldArr[i] = new int [col];
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            oldArr[i][j] = arr[i][j];
    display2DArray(oldArr, row, col);

    change2DDimension(oldArr, newArr,row, col, newRow, newCol);
    display2DArray(newArr, newRow, newCol);

    return 0;
}