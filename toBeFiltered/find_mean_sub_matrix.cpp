#include<iostream>


using namespace std;


int main()

{


	int m,n;
	float	mean;
	cin>>m>>n>>mean;
	int matrix[m][n];
	float mean_matrix[m+1][m+1][n+1][n+1];
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; j < n;j++)
		{
			cin>>matrix[i][j];
		}
	}

	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n;j++)
		{
			if( i == 0 || j == 0)
			{
				if(i == 0 && j == 0)
					mean_matrix[0][i][0][j] = matrix[i][j];
				else if(i == 0)
					mean_matrix[0][i][0][j] = (mean_matrix[0][i][0][j-1] * j + (float)matrix[i][j])/(j+1);
				else
					mean_matrix[0][i][0][j] = (mean_matrix[0][i-1][0][j] * i + (float)matrix[i][j])/(i+1);

			}
			else
			{
	
				int sum = 0;
				for(int k = 0; k <=i; k++)
					for(int l = 0; l <= j; l++)
						sum += matrix[k][l];
				mean_matrix[0][i][0][j] = ((i+j+2) * sum + mean_matrix[0][i-1][0][j-1] *i*j)/((i+1)*(j+1));

				if(mean_matrix[0][i][0][j] == mean)
						{							cout<<mean<<"\t"<<i<<"\t"<<j<<endl;goto ex;}
				for( int k = 0; k < i; k++)
					for(int l = 0; l < j; l++)
					{
						mean_matrix[k][i][l][j] = (mean_matrix[0][i][0][j]*(i+1)*(j+1) -  mean_matrix[0][k][0][l]*(k+1)*(l+1)) / ((i-k)*(j-l));
						if(mean_matrix[k][i][l][j] ==  mean)
						{							cout<<mean<<"\t"<<k<<"\t"<<i<<"\t"<<l<<"\t"<<j<<endl;goto ex;}
					}

			}

		}
	}
ex:;
	


	return 0;
}
