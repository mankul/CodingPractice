#include<iostream>


// find maximum sum subarray. containing netative integers.

using namespace std;


int main(){



    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }

    int maxsum = 0;
    int sum = 0;

    int left = 0, right = 0;
    int max_left = 0;

    for(int i = 0; i < n; i++){
        sum += arr[i];
        if(sum > maxsum){
            maxsum = sum;
            right = i;
            max_left = left;
        }
        if(sum < 0){
            sum = 0;
            left = i+1;
        }

    }

    cout<<"MaxSum "<<maxsum<<", leftIndex "<<max_left<<", RigthIndex "<<right<<endl;


    return 0;
}