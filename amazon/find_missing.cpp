#include<iostream>
#include<vector>

using namespace std;


void naive_solution(int size){
    vector<int> hash_array(size+1,0);
    int number;
    for(int i = 0 ; i < size; i ++){
        cin>>number;
        hash_array[number-1] = 1;
    }
    for(int i = 0 ; i < size + 1; i++){
        if(hash_array[i] == 0){
            cout<<i+1<<endl;
            break;
        }
    }

}
void smart_solution(int size){
    int number;
    int sum = 0;
    for(int i = 0 ; i < size; i++){
        cin>>number;
        sum+=number;
    }
    int expected_sum = ((size+1) * (size+2))/2;
    number = expected_sum - sum;
    cout<<number<<endl;
}


int main(){

    int size, number;
    cin>>size;
    

    smart_solution(size);

    return 0;
}