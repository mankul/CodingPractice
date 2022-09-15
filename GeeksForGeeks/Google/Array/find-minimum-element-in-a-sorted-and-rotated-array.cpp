#include<iostream>


using namespace std;


int main(){

    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i< n; i++)
        cin>>arr[i];

    int arr_size = n;
    int mid, i;
    if(arr[0] < arr[n-1]){
        cout<<arr[0];
    }
    else
    {
        while( i < n){
            mid = (i + n)/2;
            if(arr[mid] < arr[mid-1]){
                break;
            }
            else{
                if(arr[i] > arr[mid]){
                    // min lies here
                    n = mid;
                }
                else{
                    i = mid;
                    // mid lies here
                }
            }
        }
        cout<<arr[mid];

    }
    cout<<endl;



    return 0;
}