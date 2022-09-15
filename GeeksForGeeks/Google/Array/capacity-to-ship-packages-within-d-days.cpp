#include<iostream>


using namespace std;


int main(){


    int num, D;
    cin>>num>>D;
    int arr[num];
    int k = -1;
    int cap = 0;
    for(int i = 0 ; i < num; i++){
        cin>>arr[i];
        k = k > arr[i]? k: arr[i];
        cap += arr[i];
    }


    int mid;
    int count , sum;
    

    while(k < cap){
        mid = (k + cap)/2;
        sum = 0;
        count = 0;
        for(int i = 0; i < num; i++){
            if(sum > mid){
                count+=1;
                sum=arr[i];
            }
            else if( sum == mid){
                count+=1;
                sum = 0;
            }
            else
                sum += arr[i];
        }
        if(count>D){
            k = mid+1;
        }
        else if(count < D)
            cap = mid-1;
        else 
            break;
    }

    cout<<mid<<endl;
    


    return 0;
}