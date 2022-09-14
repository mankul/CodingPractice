#include<iostream>


using namespace std;


// if array is strictly increasing, strictly decreasing, or a flat array(complete flat array)
int peakElementInSortedArray(int arr[], int n){
    int left = 0, right = n-1, mid;
    while(left  <= right){
        mid = (left + right)/2;
        if(arr[mid] >= arr[mid-1] && arr[mid] <= arr[mid+1]){
            return mid;
        } 
        else{
            if(arr[mid] > arr[mid-1]){
                return n-1;// assuming strictly monotonically increasing array.
            }
            else{
                return 0;// monotonically decreasing array.
            }
        }
    }
}


int peakElementInRandomArray(int arr[], int n){
    for(int i =  0; i < n ; i++){
        if(i == 0){
            if(a[i] >= a[i+1]){
                return 0;
            }
        }
        else if(i == n-1){
            if(a[i] >= a[i-1]){
                return n-1;
            }
        }
        else{
            if(a[i] >= a[i-1] && a[i] >= a[i+!]){
                return i;
            }
        }
    }
    return -1;
}



int main(){


    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n; i++){
        cin>>arr[i];
    }





    return 0;

}