#include<iostream>
#include<vector>
#include<map>
using namespace std;


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> denoms, int left, int right){
    if(left >= right)
        return;
    int pivot = (left + right)/2;
    swap(denoms[pivot], denoms[right]);
    int i = left, j = left;
    while( i !=  right-1){
        if(denoms[i] < denoms[right]){
            swap(denoms[i], denoms[j]);
            j++;
        }
        i++;
    }
    swap(denoms[j], denoms[right]);
}


int main(){


    int coinsCount, number;
    vector<int> coins;
    cin>>coinsCount>>number;
    map<int, int> coinDenom;
    int acoin;

    for(int i = 0 ; i  <coinsCount ; i++){
        cin>>acoin;
        coins.push_back(acoin);
        coinDenom[acoin] = number/acoin;
    }

    quickSort(coins, 0 , coinsCount - 1);

    // for(int i = 0 ; i < coinsCount; i++){
        // vector<int> 
    // }

    
    // vector<int , vector<int> > allCostMatrix( number, (vector<int> (coinsCount, 0) ) );
    int allCostMatrix[number+1][coinsCount] ;
    

    for(int i = 0; i < coinsCount; i++){
        for(int j = 0; j <= number; j++){
            int coin = coins[i];
            allCostMatrix[j][i] = ((j-coin) == 0)?1: 0;
            for(int k = 0; k < i; k++){
                    allCostMatrix[j][i] += allCostMatrix[j][k];
            }
        }   
    }

    cout<<allCostMatrix[number][coinsCount-1]<<endl;

    // recursion(allCostMatrix, coins, number);


    return 0;
}