#include<iostream>
#include<vector>
using namespace std;


int minimum(int a, int b, int c){
    return a < b? a < c ? a: c : b < c ? b : c;
}


int minimum_duty(vector<int> arr, vector<int> &position_memory, int position, int countOfNumbers){
    
    if(position_memory[position] != 0)
        return position_memory[position];

    // array stores numbers starting from 0
    if(position == countOfNumbers - 1){
        return arr[position];
    }
    if(position == countOfNumbers - 2){
        return arr[position] > arr[position + 1] ? arr[position + 1] : arr[position];
    }
    if(position == countOfNumbers -3){
        return minimum( arr[position] , arr[position + 1], arr[position + 2]);
    }


    position_memory[position] = minimum(\
        minimum_duty(arr, position_memory, position+1, countOfNumbers),\
        minimum_duty(arr, position_memory, position + 2, countOfNumbers),\
        position_memory[position] + minimum_duty(arr, position_memory, position + 3, countOfNumbers)\
        );
    return position_memory[position];
}


int main(){

    int countOfNumbers;
    cin>>countOfNumbers;
    int number;
    vector<int> arr;
    vector<int> position_memory(countOfNumbers, 0);
    for(int i = 0; i < countOfNumbers; i++)
    {
        cin>>number;
        arr.push_back(number);
    }


    if(countOfNumbers <= 3){
        if(countOfNumbers==1)
            cout<<arr[0];
        else if (countOfNumbers == 2)
            cout<< ( (arr[0]>arr[1])? arr[0] :arr[1]);
        else
            cout<< minimum(arr[0], arr[1], arr[2]);
        cout<<endl;
    }


    else{
        cout<<minimum_duty(arr, position_memory, 0, countOfNumbers -1 )<<endl;
    }
    return 0;
}