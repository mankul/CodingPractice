

// COMPLETED


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int siz = nums.size();
        vector<int> new_num(siz);
        int pos_arr[siz/2];
        int neg_arr[siz/2];
        int j = 0;
        int k = 0;
        for(int i = 0; i < siz; i ++){
            if(nums[i] > 0){
                pos_arr[j] = i;
                j++;
            }
            else{
                neg_arr[k] = i;
                k++;
            }
        }
        for(int i = 0, j = 0, k = 0; i < siz; i++){
            if(i%2 == 0){
                // even index, number should be +ve
                new_num[i] = nums[pos_arr[j]];
                j++;
            }
            else{
                // odd index
                new_num[i] = nums[neg_arr[k]];
                k++;
            }
        }
        return new_num;
    }
};

int main(){
    Solution s;
    vector<int> arr;
    int num, number;
    cin>>num;
    for(int i = 0 ; i < num; i++){
        cin>>number;
        arr.push_back(number);
    }

    arr = s.rearrangeArray(arr);
    for(int i = 0;i < num; i++){
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}
