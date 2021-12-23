#include<iostream>


// find the respective element which is to be find in row and column wise sorted matrix.

// recurrence relation is at point (i,j) if < m[i][j]

using namespace std;





pair<int, int> find_element_by_sorted_trick(int * matrix, int element, int row, int column, int rows, int columns){
    // int a,b;
    // initially row 0 and column n-1.
    int value = *(matrix + row * columns + column);
    cout<<row<<"\t"<<column<<"\t"<<value<<endl;
    if (element == value)
        return make_pair(row, column);
    else if (element > value){
        if (row<rows)
            return find_element_by_sorted_trick(matrix, element, row+1, column, rows,columns);
        else
            return make_pair(-1,-1);
        
    }
    else{
        if(column>=0)
            return find_element_by_sorted_trick(matrix, element, row,column-1,rows, columns );
        
        else
            return make_pair(-1,-1);

    }

    
        

}




int main(){

    int test_cases;
    int rows, columns, element;
    cin>>test_cases;
    for(int i = 0; i< test_cases; i++){
        cin>>element;
        cin>>rows>>columns;
        int matrix[rows][columns];
        for( int j = 0; j< rows; j++){
            for(int k = 0; k < columns; k++)
                cin>>matrix[j][k];
        }


        // find_element((int *)matrix, element, 0,0, rows-1, columns-1, columns);
        pair<int, int> output = find_element_by_sorted_trick((int *)matrix, element, 0, columns-1,rows,columns);
        cout<<output.first<<"\t"<<output.second<<endl;

    }

}
















int find_element(int * matrix, int element, int left_row_index,int left_column_index, int right_row_index, int right_column_index, int columns)
{
    
    int row_index = (left_row_index + left_column_index )/2;
    int column_index = (left_column_index + right_column_index)/2;

    if (left_row_index == right_row_index && left_column_index == right_column_index){
        if ( element != *(matrix + left_row_index*columns + left_column_index) )
            return -1;
        else
            return 1;
    }
    else if ( left_row_index == right_row_index){
        if(element == *(matrix + left_row_index*columns + column_index))
            return 1;
        else if(element > *(matrix + left_row_index*columns + column_index))
            return find_element(matrix, element, left_row_index, left_row_index, column_index+1, right_column_index, columns);
        else 
            return find_element(matrix, element, left_row_index, left_row_index, left_column_index, column_index-1, columns);
    }
    else if ( left_column_index == right_column_index){
        if (element == *(matrix + row_index* columns + left_column_index))
            return 1;
        else if(element > *(matrix + row_index * columns + left_column_index))
            return find_element(matrix, element, row_index+1, right_row_index, left_column_index, right_column_index,columns);
        else
            return find_element(matrix, element, left_row_index, row_index-1, left_column_index, right_column_index, columns);

    }
    

    if (element == *(matrix + row_index*columns + column_index) )
        return 1;
    else if (element > *(matrix + row_index*columns + column_index) ){
        int a = find_element(matrix, element, row_index+1, column_index+1, right_row_index, right_column_index, columns)  ;
        int b = find_element(matrix, element, left_row_index,column_index+1, row_index, right_column_index, columns)  ;
        int c = find_element(matrix, element, row_index+1, left_column_index, right_row_index,column_index, columns)  ;
        return a | b | c;
    }
    else{

        int a = find_element(matrix, element, left_row_index, left_column_index, row_index, column_index, columns)  ;
        int b = find_element(matrix, element, left_row_index,column_index, row_index, right_column_index, columns)  ;
        int c = find_element(matrix, element, row_index, left_column_index, right_row_index,column_index, columns)  ;
        return a | b | c;

    }

}
