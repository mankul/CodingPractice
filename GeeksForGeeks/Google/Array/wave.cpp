/*

a)

    3       4       6       8       10
1       2       5       7       9


b) 

1 2 3 4 5 6 7 8 9 10

2       4       6       8       10  
    1       3       5       7       9
*/



#include<iostream>
#include<vector>
using namespace std;



void swap(int & a, int &b){
    int temp = a;
    a = b;
    b = temp;
}



// sorting function


int main(){

    int number;
    cin>>number;
    vector<int> arr(number);
    for(int i = 0; i < number; i++)
        cin>>arr[i];


    sort(arr.begin(), arr.end());

    for(int i = 0 ; i < number-1; i++){
        if(i %2 == 0)
            swap(arr[i], arr[i+1]);
    }

    for(int i = 0; i< number; i++)
        cout<<arr[i];

    cout<<endl;

    return 0;
}