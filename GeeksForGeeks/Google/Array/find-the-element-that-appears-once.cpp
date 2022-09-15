#include<iostream>


using namespace std;

int main(){

    int n;
    cin>>n;
    int arr[32] = {0};
    int num = 0;
    for(int i = 0; i < n ;i++){
        cin>>num;
        for(int j = 0; j < 32; j++){
                if( (num & 1<<j) > 0)
                    arr[j] += 1;
        }
    }

    num = 0;
    for(int i = 0; i < 32; i++){
        if((arr[i] % 3 ) == 1){
            num += (1<<i);
        }
    }

    cout<<num<<endl;


    


    return 0;
}