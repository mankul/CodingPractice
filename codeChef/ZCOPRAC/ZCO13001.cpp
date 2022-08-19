#include<iostream>
#include<vector>

using namespace std;




void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void quickSort(vector<int> & arr, int left, int right){
    if(left >= right)
        return;
    
    int pivot  = (left + right)/2;

    swap(arr[pivot], arr[right]);

    int i = left, j = left;

    while(i < right ){
        if(arr[i] <= arr[right]){
            swap(arr[i], arr[j]);
            j+=1;
        }
        i++;
    }
    swap(arr[right], arr[j]);

    quickSort(arr, left, j - 1);
    quickSort(arr, j+1, right);
}





int main(){


    int n;
    vector<int> s;
    cin>>n;
    int num;
    for(int i = 0; i < n ; i++){
        cin>>num;
        s.push_back(num);
    } 



    // when array is small, run time complexity is O(n^2)
    // long long sum = 0;

    // for(int i = 0; i < n-1; i ++) {
    //     for(int j = i+1; j < n; j++){
    //         sum += (s[i]-s[j] < 0)? s[j] - s[i]: s[i]-s[j];
    //     }
    // }
    // cout<<sum<<endl;


    // other way , first sort then apply the solution

    // sum ( k-1 * a(k) - sum(1, k-1))

    quickSort(s,0, n-1);

    long long sum = 0;
    long long sub_sum = 0;
    long long arr_sum = 0;
    for(int i = 1; i <n; i++ ){
        sum += (i) * s[i];
        arr_sum += s[i-1];
        sub_sum += arr_sum; 
    }

    sum -= sub_sum;
    cout<<sum<<endl;






    return 0;
}