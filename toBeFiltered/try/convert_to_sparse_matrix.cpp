#include<iostream>

using namespace std;


int main()

{

	int row, column, row1, column1;
	cout<<"enter rows and columns respectively"<<endl;
	cin>>row>>column;
	int C[row][column];
	cout<<"enter rows and column of second matrix resp"<<endl;
	cin>>row1>>column1;
	int M[row1][column1];
	cout<<"enter "<<column<<" elements per row "<<endl;
	int size = 0;
	int size1 = 0;
	for(int i = 0; i < row; i++)
	{
		for( int j = 0; j < column; j++)
		{
			cin>>C[i][j];
			if(C[i][j] != 0)
				size++;
		}
	}

	cout<<"\nsecond matrix "<<endl;
	cout<<"enter "<<column1<<" elements per row "<<endl;
	for(int i = 0; i < row1; i++)
	{
		for( int j = 0; j < column1; j++)
		{
			cin>>M[i][j];
			if(M[i][j] != 0)
				size1++;
		}
	}
	int sparse_matrix[size][3];
	int second_sparse_matrix[size1][3];
	int l = 0;
	cout<<"row, column, value:"<<endl;
	for(int i = 0; i < row; i++)
	{
		for( int j = 0; j < column; j++)
		{
			if(C[i][j] != 0)
			{
				sparse_matrix[l][0] = i;
				sparse_matrix[l][1] = j;
				sparse_matrix[l][2] = C[i][j];
				l++;

			}
		}
	}
	
	l = 0;
	for(int i = 0; i < row1; i++)
	{
		for( int j = 0; j < column1; j++)
		{
			if(M[i][j] != 0)
			{
				second_sparse_matrix[l][0] = i;
				second_sparse_matrix[l][1] = j;
				second_sparse_matrix[l][2] = M[i][j];
				l++;

			}
		}
	}


	l=0;
	while(l < size)
	{
		cout<<sparse_matrix[l][0]<<", ";
		cout<<sparse_matrix[l][1]<<", ";
		cout<<sparse_matrix[l][2]<<endl;
		l++;
	}

	for( l = 0; l < size1; l++)
	{

		cout<<second_sparse_matrix[l][0]<<", ";
		cout<<second_sparse_matrix[l][1]<<", ";
		cout<<second_sparse_matrix[l][2]<<endl;
	}
}
