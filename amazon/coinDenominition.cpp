#include<iostream>
#include<vector>
#include<map>
using namespace std;




// this recursion will solve if the order of coins matters.

int recurse(vector<int> &cost, int currentValue, vector<int> coins){
    if( currentValue < 0)
        return 0;
    if(currentValue == 0)
        return 0;
    if(cost[currentValue] != 0)
        return cost[currentValue];
    for( int i = 0 ; i < coins.size(); i++){
        int coin = coins[i];
        int restValue = currentValue - coin;
        if(restValue == 0){
            cost[currentValue] +=1;
        }
        else{
            cost[currentValue] += recurse(cost, restValue, coins);
        }
    }
    cout<<"returning cost "<<cost[currentValue]<<" of current value "<<currentValue<<endl;
    return cost[currentValue];
}



int recursion(vector<int>& cost,int currentValue, int coinsCount, map<int, int> coins){
    if(currentValue <= 0){
        return 0;
    }
    if(cost[currentValue] != 0){
        cout<<"current value is "<<currentValue<<endl;
        return cost[currentValue];
    }
    
        
    for(int costIter = 1; costIter < currentValue; costIter ++)
    {
        
        int restCost = currentValue - costIter;
        // cout<<"rest "<<restCost<<" current"<<currentValue<<" iter "<<costIter<<endl;
        if(costIter <= restCost)
            cost[currentValue] += recursion(cost, restCost, coinsCount, coins ) *\
                        recursion(cost, costIter, coinsCount, coins) ;
                        
        
        if(restCost == 1)
            cost[currentValue] += 1;
         
    }


    if(coins.find(currentValue) != coins.end()){
        cost[currentValue] += 1;
        cout<<"coin found for "<< currentValue<<endl;
    }

    cout<<"current cost "<<currentValue<<" "<<cost[currentValue]<<endl;
            
    return cost[currentValue];

}


// void iterate(vector<int> cost, int number, int coinsCount, map<int, int> coins){

//     for(int i = 1; i <= number; i++){       
//         for(int j = 0; j < coinsCount; j++){
//             if(i - coins[j] > 0){
//                 cost[i] += cost[i - coins[j]];
//             }
//             else if(i - coins[j] == 0){
//                 cost[i] += 1;
//             }
//         }
//     }
// }

int main(){
    int number, coinsCount;
    cin>>coinsCount;
    cin>>number;
    // map<int, int> coins;
    vector<int> coins;
    int denominition;
    for(int i = 0; i < coinsCount; i++)
    {
        cin>>denominition;
        coins.push_back(denominition);//] = 1;
    }

    vector<int> cost(number+1,0);
    cout<<coinsCount<<endl;
    for(int i = 0; i<= number; i++)
        cout<<cost[i];
    cout<<endl;
    for(int i = 0 ; i < coinsCount;i++)
        cout<<i<<" "<<coins[i]<<endl;
    cout<<endl;

    // int result = recursion(cost, number, coinsCount , coins);
    int result = recurse(cost, number, coins);
    for(int i = 1; i<= number; i++)
        cout<<i<<" "<<cost[i]<<endl;
    return 0;
}