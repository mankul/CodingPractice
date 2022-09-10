#include<iostream>
#include<vector>
using namespace std;

int findMax(string str){
    int minIndex = 0;
    for (int i = 1; i < str.length(); i++){
        if(str[minIndex] < str[i]){
            minIndex = i;
        }
    }
    // cout<<"min index is "<<minIndex<<endl;
    return minIndex;
}


int slotWheels(vector<string> history){
    int n = history.size();
    string str = history[0];
    int numberOfWheels = str.length();
    // cout<<numberOfWheels<<endl;
    int minStops = 0;
    for (int i = 0; i < numberOfWheels; i++)
    {
        int maxStops = 0;
        // cout<<history[i]<<endl;
        for(int j = 0 ; j < n; j++){
            // cout<<"string is "<<history[j];
            int index = findMax(history[j]);
            int maxSt = history[j][index] - '0';
            if(maxStops < maxSt ){
                maxStops = maxSt;
            }
            history[j].erase(index,1);
            // cout<<"string after is "<<history[j]<<endl;
        }
        minStops += maxStops;

    }
    return minStops;
}

int main(){


vector<string> history;
history.push_back("719");
history.push_back("514");
history.push_back("991");
cout<<slotWheels(history);

return 0;
    
}