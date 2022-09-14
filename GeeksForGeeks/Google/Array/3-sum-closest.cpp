#include<iostream>

using namespace std;



int * mergeSort(int arr[], int left, int right){// inclusive
    if(left == right){
        return &arr[left];
    }
    int mid = (left + right)/2;
    int * arr1 = mergeSort(arr, left, mid);
    int * arr2 = mergeSort(arr, mid + 1, right);
    int i = left;
    int j = mid+1;
}

int main(){


    int n;
    int sum;
    cin>>sum;
    cin>>n;
    int arr[n];

    for(int i = 0 ; i < n ; i++)
        cin>>arr[i];



    int closestSum = -1;
    for(int i  = 0 ; i  <  n ; i++){
        int j = 0;
        int k = n-1;
        int currentSum = arr[i];
        while(j < k){
            if(j == i){
                j+=1;
            }
            else if(k == i){
                k-=1;
            }
            else if(sum )
        }
    }



    return 0;
}