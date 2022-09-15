#include<iostream>
#include<vector>
#include<map>


#define unit long long

using namespace std;



struct node
{
    int min_index;
    int max_index;
};


typedef struct node index;


int minimum(vector<unit> arr, int first, int second){
    return ( arr[first] < arr[second] ) ? first: second;
}

int maximum(vector<unit> arr, int first, int second){
    return ( arr[first] > arr[second] ) ? first: second;
}




int main(){
    int test;
    cin>>test;
    for(int t = 0; t  < test ; t++){
        int n;
        cin>>n;
        vector<unit> arr(n);
        for(int i  = 0 ; i < n ; i++)
            cin>>arr[i];
        
        vector< vector<index> > array( n, vector<index> (n));

        unit interestingValue;
        unit maxValue = -10000000000;
        unit minValue = 10000000000;

        for(int i = 0; i < n; i++){
            for(int j = i ; j < n; j++){
                if(i == j){
                    array[i][j].min_index = i;
                    array[i][j].max_index = i; 
                }
                else{
                    array[i][j].min_index = minimum(arr, array[i][j-1].min_index, j); // at (j,j) assumes max and min values are present.
                    array[i][j].max_index = maximum(arr, array[i][j-1].max_index, j);
                }

                interestingValue = arr[array[i][j].max_index] * arr[array[i][j].min_index];
                if(maxValue < interestingValue){
                    maxValue = interestingValue;
                }
                if(minValue > interestingValue){
                    minValue = interestingValue;
                }
            }
        }
        
        cout<<minValue <<" "<<maxValue<<endl;

    }



    return 0;
}