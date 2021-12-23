#include<iostream>
#include<vector>
using namespace std;




int main(){

    int arr_size, first, second;
    cin>>arr_size;
    vector< pair<int,int> > arr;
    for(int i = 0; i < arr_size; i++){
        cin>>first>>second;
        pair<int, int> new_pair = make_pair(first, second);
        arr.push_back(new_pair);
    }
    sort(arr.begin(), arr.end(), [] (const pair<int, int> & x1, const pair<int, int> & x2) { return (x1.first < x2.first);});
    vector<int> opt(arr_size,0);// opt(k,n) will be represented by opt(k)
    int opt_temp = 0;
    opt[arr_size-1] = 1;
    for(int i = arr_size-2; i >= 0 ; i--)
    {
        if(arr[i].second <= arr[i+1].first)
            opt[i] = opt[i+1] + 1;

        else{
            for(int j = i + 2 ; j <arr_size; j++){
                if(arr[j].first >= arr[i].second)
                    {
                        opt_temp = opt[j] + 1;
                        break;
                    }
                else {
                    if(j == arr_size-1)
                        opt_temp = 1;
                }
            }
            opt[i] = opt[i+1] > opt_temp? opt[i+1] : opt_temp;
        }
        
    }

    cout<<opt[0]<<endl;


    return 0;
}
