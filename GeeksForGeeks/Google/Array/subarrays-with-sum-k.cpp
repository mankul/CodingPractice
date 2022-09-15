#include<iostream>


using namespace std;


int main(){


    int k, n;
    cin>>k;
    cin>>n;
    
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }


    int sum = 0;
    int count  = 0;
    int j = 0, i = 0;
    while(i < n || (sum > k && j < n)){
        if(sum < k){
            sum += arr[i];
            i += 1;
        }
        else if ( sum > k){
            sum -= arr[j];
            j += 1;
        }
        else{
            count += 1;
            sum = sum + arr[i] - arr[j];
            
            j+=1;
            i+=1;
        }
    }
    if(sum == k)
        count += 1;
    cout<<count<<endl;

    return 0;
}