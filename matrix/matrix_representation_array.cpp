


#include<iostream>

#define ROWS 10
#define COLUMNS 10





#define x1 1
#define x2 x1, x1
#define x4 x2, x2
#define x8 x4, x4
#define x16 x8, x8
#define x32 x16, x16
#define x64 x32, x32
#define x128 x64, x64






using namespace std;



void calculate_matrix_multiplication(int *matrix1, int * matrix2 )//, int *, int row1, int row2, int col1, int col2)
{

    int matrix[ROWS][COLUMNS];

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j< COLUMNS; j++)
        {
            int sum = 0;
            
            for(int l = 0; l < COLUMNS; l++)
                sum+= *(matrix1 + i *COLUMNS + l ) * *(matrix2 + l*ROWS + j);

            matrix[i][j] = sum;

        }
    }

    for(int i = 0;i < ROWS; i++){
        for(int j = 0; j <COLUMNS; j++)
        {
            std::cout<<matrix[i][j]<<"\t";
        }
        std::cout<<std::endl;
    }

    std::cout<<"function called"<<std::endl;
}

int main(){

    // 
    
    
    int matrix1[ROWS][COLUMNS] = { x64, x32, x4 };
    int matrix2[COLUMNS][ROWS] = { x64, x32, x4 };

    for (int i = 0;i < ROWS; i++){
        for (int j =0; j< COLUMNS; j++){
         matrix1[i][j] += i+j;
         matrix2[i][j] += i+j;
        }
    }


    // pointer conversion to the one d pointer
    calculate_matrix_multiplication((int *)matrix1, (int *)matrix2);


}