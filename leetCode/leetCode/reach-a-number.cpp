// You are standing at position 0 on an infinite number line. There is a destination at position target.
// You can make some number of moves numMoves so that:
// On each move, you can either go left or right.
// During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.
// Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.


#include<iostream>

using namespace std;

class Solution {
public:

    // once we reach number with minimum number of moves, i.e adding numbers in one direction we will 
    // encounter 2 cases, (I) if the number is reached (II) number is crossed by sum , then we will look
    // for the even difference between the number so that the difference of some m \in [k] the number is 
    // subtracted twice so to get the solution, until we keep adding incrementing k. 

    int reachNumber(int target){
        target = abs(target);
        int k = 1;
        long sum = 0;
         while(sum < target){
             sum += k;
             k+=1;
         }
         if(sum > target){
             while((sum - target) %2 != 0){
                 sum += k;
                 k+=1;
             }
         }
        return k-1;
    }
    // Not optimal
    int reachNumberWithMoves(int target) {
        int k = 1;
        long sum = 0;
        while( sum != target){
            if(sum > target){
                sum -= 2*(k-1);
                sum += k;
                k+=1;
            }
            else{
                sum += k;
                k+=1;
            }
        }
        return k-1;
    }
};

int main(){
    Solution s;
    int target = 10;
    for(int i = 0 ; i < target; i++)
        cout<<target+i<<"\t"<<s.reachNumber(target+i)<<endl;
    return 0;
}