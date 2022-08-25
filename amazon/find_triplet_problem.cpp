#include<iostream>
#include<vector>
#include<map>


using namespace std;




int main(){

    int n;
    cin>>n;
    int temp;
    vector<int> array;
    map<int, int> hash;
    for(int i = 0; i < n; i++){
        cin>>temp;
        array.push_back(temp);
        hash[temp] = i;
    }

    
    // sorting is not required, because we still have to compare all possible pairs
    // quickSort(array, 0 , n-1);

    bool isPresent = false;
    for(int i = 0; i < n-1 ; i++){
        for(int j = i+1; j < n; j++){
            if( hash.find( array[i] + array[j] ) != hash.end() ){
                cout<<i<<" "<<j<<" "<<hash[array[i] + array[j]]<<endl;
                isPresent = true;
                break;
            }
        }
        if(isPresent)
            break;
    }
    if(!isPresent)
        cout<<0<<endl;


    return 0;
}