    #include<iostream>
    #include<vector>



    using namespace std;


    #define unit long


    struct InterestingNode {
        int min_index;
        int max_index;
    };


    typedef struct InterestingNode Node;


    int minimum(vector<unit> arr, int firstIndex, int secondIndex){
        return arr[firstIndex] < arr[secondIndex] ? firstIndex: secondIndex;
    }


    int maximum(vector<unit> arr, int firstIndex, int secondIndex){
        return arr[firstIndex] > arr[secondIndex] ? firstIndex: secondIndex;
    }



    int main(){


        int test;
        cin>>test;
        for(int t = 0; t < test; t++){
            int n;
            int lowestIndex = -1;
            int highestIndex = -1;
            bool negative = false;
            bool positive = false; 
            cin>>n;

            unit maxValue = -10000000000;
            unit minValue  = 10000000000;
            vector<unit> arr(n);
            for(int i = 0; i < n; i++){
                cin>>arr[i];
                if(arr[i] > 0)
                    positive = true;
                if(arr[i] < 0)
                    negative = true;
                if(arr[i] > maxValue)
                    maxValue = arr[i];
                if(arr[i] < minValue)
                    minValue = arr[i];
            }


            int maxInterest;
            int minInterest;
            if(negative && !positive){
                maxInterest = minValue * minValue;
                minInterest = maxValue * maxValue;
            }
            else if(negative && positive){
                minInterest = minValue * maxValue;
                maxInterest = maxValue * maxValue > minValue * minValue ? maxValue * maxValue : minValue * minValue; 
            }
            else{
                minInterest = minValue * minValue;
                maxInterest = maxValue * maxValue;
            }
            cout<<minInterest<<" "<<maxInterest<<endl;

        }
    return 0;

    }