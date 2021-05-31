
# include<iostream>
#include<vector>


#define ROWS 10
#define COLUMNS 10

#define vec std::vector<int>

#define Matrix std::vector<vec >


#define x1 1
#define x2 x1, x1
#define x4 x2, x2
#define x8 x4, x4
#define x16 x8, x8
#define x32 x16, x16
#define x64 x32, x32



// using namespace std;




int main()
{

    Matrix matrix(ROWS, vec(COLUMNS)) ;
    // Matrix matrix(ROWS, vec(COLUMNS, 10)) ;


    
    for(int i = 1; i < ROWS; i++){
        for( int j =0; j < COLUMNS; j++)
        {
            std::cout<<matrix[i][j]<<"\t";// = i+j;
        }
        std::cout<<std::endl;

    }
    Matrix newMatrix;

    newMatrix = matrix;


    





}