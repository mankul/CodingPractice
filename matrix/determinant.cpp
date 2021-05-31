

#include<iostream>

#define x1 1
#define x2 x1,x1
#define x4 x2, x2
#define x8 x4,x4
#define x16 x8,x8
#define x32 x16,x16
#define x64 x32,x32


#define ROWS 3
#define COLUMNS 3


// as it is a square matrix the m = n = size
int  calculate_determinant( int * matrix , int size){
    if ( size  == 1){
        return *(matrix);
    }
    int arr[size-1][size-1];
    int minor, cofactor;
    int sign = 1;
    int det = 0;
    for(int i = 0; i<size; i++){
        // recursion for the respective element

        for(int j = 1; j < size; j++)
            for(int k = 0; k< size; k++){
                if ( k < i)
                    arr[j-1][k] = *(matrix + size * j + k);
                else if(k > i)
                    arr[j-1][k-1] = *(matrix + size * j + k);
                
            }
        cofactor = calculate_determinant((int *)arr, size-1);
    minor = *(matrix + i) * cofactor * sign;
    sign*=(-1);
    det+=minor;
    }
    return det;

}


int main(){

    int matrix [ROWS][COLUMNS] = { x8,x1};

    for(int i =0; i< ROWS; i++)
        for(int j = 0; j<COLUMNS; j++){
            matrix[i][j] += (i+j);
            std::cout<<matrix[i][j]<<"\t";
        }

    


    int size=ROWS;
    int det = calculate_determinant((int *)matrix, size);
    std::cout<<"determinant is "<<det<<std::endl;
    return 0;
}