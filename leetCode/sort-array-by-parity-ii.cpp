



// COMPLETED

#include<iostream>
#include<vector>


using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int siz = nums.size();
        int even_nums[siz/2];
        int odd_nums[siz/2];
        for(int i = 0, k = 0, j = 0; i < siz; i++)
        {
            if(nums[i]%2 == 0){
                even_nums[k] = nums[i];
                k++;
            }
            else
            {
                odd_nums[j] = nums[i];
                j++;            
            }
        }
        for(int i = 0, j = 0,k = 0;i < siz; i++){
            if(i%2 == 0){
                nums[i] = even_nums[k];
                k++;
            }
            else{
                nums[i] = odd_nums[j];
                j++;
            }

        }
        return nums;
    }
};

int main(){

    vector<int> nums;
    int num, number;
    cin>>num;
    for(int i = 0; i< num; i++)
    {
        cin>>number;
        nums.push_back(number);
    }
    Solution s;
    nums = s.sortArrayByParityII(nums);
    for(vector<int>::iterator iterator = nums.begin(); iterator != nums.end(); iterator++)
        cout<<*iterator<<"\t";
    cout<<endl;
    return 0;
}