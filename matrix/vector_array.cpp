


#include<iostream>
#include<vector>

#define MAXSIZE 100
#define Matrix 

int main()
{


    std::vector< std::vector<int> > arr(MAXSIZE, std::vector<int> (MAXSIZE, 2));



    std::vector<int> mat(MAXSIZE, 1);

    // for ( int i =0 ;i <= MAXSIZE; i++)
    // {
    //     arr.push_back(i);
    // }


    std::cout<<arr.size();
    for ( int i =0 ;i < MAXSIZE; i++)
    {
        std::cout<<arr[i][i]<<"\t"<<mat[i]<<std::endl;
    }
}