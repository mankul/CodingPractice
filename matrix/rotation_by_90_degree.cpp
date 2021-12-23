#include<iostream>


using namespace std;


void rotate_matrix(int * matrix, int rows, int columns, int * new_matrix){
//

for(int i = 0; i < rows; i++)
    for(int j = 0; j < columns; j++)
        *(new_matrix + columns * i + j) = *(matrix + columns * (rows - j - 1) + i);



}



void rotate_matrix_by_cycle( int * matrix, int size){
    // make a cycle
    // assumption it is a square matrix
    int temp;
    int lim = size - 1;

    for (int i = 0; i < size/2; i++ ){
        for( int j = 0; j < size - 2*i; j++){
            int gap = i+j;
            int skip = size - 1 - gap;
            
            temp = *(matrix + lim *gap +gap);
            cout<<temp<<endl;
            *(matrix + lim *gap +gap) = *(matrix + lim * skip + gap);
            *(matrix + lim *skip +gap) = *(matrix + lim * skip + skip);
            *(matrix + lim *skip +skip) = *(matrix + lim * gap + skip);
            *(matrix+lim*gap+skip-gap) = temp;
            cout<<*(matrix + lim*gap + skip-gap)<<"gap"<<endl;

        }
    }
    // int temp = matrix[rows-1][0];
    // matrix[rows-1][0] = matrix[rows-1[columns-1] ;
    // matrix[rows-1][columns-1] = matrix[0][columns-1] ;
    // matrix[0][columns-1] = matrix[0][0];
    // matrix[0][0] = temp;


}


int main(){

    int test_cases, rows;
    cin>>test_cases;
    for(int t = 0; t< test_cases; t++){
        cin>>rows;
        int matrix[rows][rows];
        for(int i = 0; i< rows; i++)
            for(int j = 0; j < rows; j++)
                cin>>matrix[i][j];

        rotate_matrix_by_cycle((int *)matrix, rows);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < rows; j++)
                cout<<matrix[i][j]<<"\t";
            cout<<endl;
        }
    }


    return 0;
}