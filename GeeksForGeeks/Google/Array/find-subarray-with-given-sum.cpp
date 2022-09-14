#include<iostream>
#include<vector>

using namespace std;



int main(){


    int num;
    int sum;
    cin>>num;
    cin>>sum;
    vector<int> arr(num);

    for(int i = 0 ; i < num; i++)
        cin>>arr[i];
    

    bool answer = false;
    int j = 0;// left pointer
    int i = 0;// right pointer

    int current_sum = 0;

    while(i < num || current_sum >= sum){
        cout<<current_sum<<endl;
        if(current_sum == sum){
            cout<<j<<" "<<(i-1)<<endl;
            answer = true;
            break;
        }
        else if(current_sum > sum){
            current_sum -= arr[j];
            j++;
        }
        else{
            current_sum += arr[i];
            i++;
        }
    }
    if(!answer)
        cout<<"not found"<<endl;
    



}