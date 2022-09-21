#include<iostream>
#include<map>

using namespace std;


/* * f(n) = f(n-1) + f(1)f(n-1) + f(2)f(n-2) + f(3)f(n-3) + .. + f(n-1)f(1)



*/


int calculateBalancedParenthesis(int num, map<int, int> functionMap){
    if(num <= 0)
        return 1;
    if(functionMap.find(num) != functionMap.end())
        return functionMap[num];
    functionMap[num] = 0;

    int sum = 0;    
    if(num == 1){
        sum = 1;
    }
    else{
        for(int i = 0; i < num; i++){
            int firstCount = calculateBalancedParenthesis(i, functionMap);
            int secondCount = calculateBalancedParenthesis(num - 1 -i, functionMap); // fixing outer parenthesis for this case, will avoid repeated cases.
            sum += firstCount*secondCount;
        }
    }
    functionMap[num] = sum;
    return functionMap[num];
}



int main(){


    int num;
    cin>>num;
    map<int , int> functionMap;

    cout<<calculateBalancedParenthesis(num, functionMap)<<endl;



    return 0;
}