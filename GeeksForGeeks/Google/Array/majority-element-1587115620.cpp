// find majority > N/2 times . Exor all array elements. If found > N/2 times, there is a possibility of 
// such element



#include<iostream>
#include<vector>


using namespace std;


void findSetBits(int num, vector<int> & bitArray){
    int currentBit = 0;
    while(num > 0){
        if(currentBit == bitArray.size())
            bitArray.push_back(0);
        if( (num & 1) > 0)
                bitArray[currentBit]+=1;    
        num = num>>1;
        currentBit+=1;
    }
}

int convertToNumber(vector<int> bitArray, int n){
    int number = 0;
    for(int i = bitArray.size() - 1; i >=0; i--){
        if(bitArray[i] > n/2){
            number = 2*number+1;
        }
        else
            number = number*2;
    }
    return number;
}

int main(){


    int n;
    cin>>n;
    vector<int> arr(n);
    vector<int> bitArray;
    
    
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
        findSetBits(arr[i], bitArray);
    }

    int number = convertToNumber(bitArray, n);
    
    bool found = false;
    
    for(int i = 0 ; i < n; i++){
        if(arr[i] == number){
            found = true;
            break;
        }
    }

    for(int i = 0; i < bitArray.size(); i++)
        std::cout<<i<<" "<<bitArray[i]<<" ";
    std::cout<<endl; 

    if(!found)
        std::cout<<"not found"<<endl;
    else
        std::cout<<"found "<<number<<endl;

    return 0;
}