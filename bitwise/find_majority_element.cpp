


#include<iostream>


#define INT_LEN 31



int find_majority(int * arr, int arrlen)
{
    int element = 0;
    int count;
    for(int i = 0; i < INT_LEN; i++){
            // std::cout<<(1<<i);
        count = 0;
        for(int j = 0; j < arrlen; j++)
        {
            if ((arr[j] & 1<<i) == 1)
                std::cout<<"count is "<<count<<" i value is "<<i<<std::endl;
                count++;
        }

        if (count > arrlen/2){
            std::cout<<"power is "<<1<<i<<std::endl;
            element += 1<<i;
            std::cout<<"element is "<<element<<std::endl;
        }

    }
    for(int i = 0; i < arrlen; i++)
    {
        if (arr[i] == element)
            return element;
    }
    return -1 ;   
}


int main()
{

    int test_cases, arrlen;
    std::cin>>test_cases;
    for (int i = 0; i< test_cases; i++)
    {
        std::cin>>arrlen;
        int arr[arrlen];
        for(int j = 0; j<arrlen; j++)
            std::cin>>arr[j];
        // for (int j = 0 ; j < arrlen;j++)
        //     std::cout<<arr[j];
        // std::cout<<find_majority(arr, arrlen)<<std::endl;
    }
}