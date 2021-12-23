

#include<iostream>
#include<vector>



#define ROWS 10
#define COLUMNS 10


#define x1 1
#define x2 x1,x1
#define x4 x2,x2
#define x8 x4,x4
#define x16 x8,x8
#define x32 x16,x16
#define x64 x32,x32


void transpose( int A[][COLUMNS], int B[][ROWS])
{
    for(int i =0; i< ROWS; i++){
        for(int j = 0;j< COLUMNS; j++)
            B[j][i] = A[i][j];
     }
}


int main(){

int matrix[][COLUMNS] = {x64, x32, x4};


int transposeMatrix [COLUMNS][ROWS];
for( int i = 0; i < ROWS; i++){
    for(int j = 0; j < COLUMNS; j++){
        matrix[i][j]+=(i);
        std::cout<<matrix[i][j]<<"\t";
    }
    std::cout<<std::endl;
}

for(int i =0; i< ROWS; i++){
for(int j = 0; j< COLUMNS; j++)
std::cout<<matrix[i][j]<<"\t";
std::cout<<std::endl;
}
transpose(matrix, transposeMatrix);

for(int i =0; i< ROWS; i++){
for(int j = 0; j< COLUMNS; j++)
std::cout<<transposeMatrix[i][j]<<"\t";
std::cout<<std::endl;
}



}