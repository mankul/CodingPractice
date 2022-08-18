#include<iostream>
#include<vector>

using namespace std;

int main(){
    int numStacks;
    int heightThreshold;
    vector<int> columnHeights;

    int holder;
    cin>>numStacks;
    cin>>heightThreshold;
    for(int i = 0; i < numStacks; i++){
        cin>>holder;
        columnHeights.push_back(holder);
    }

    int position = 0;
    bool blockPicked = false;

    while(1){
        cin>>holder;
        if(holder == 0){
            break;
        }
        else{
            switch(holder){
                case 1:
                    if (position != 0)
                        position --;
                    break;
                case 2:
                    if(position < numStacks-1)
                        position ++;
                    break;
                case 3:
                    if(columnHeights[position] != 0 && !blockPicked){
                        columnHeights[position] -= 1;
                        blockPicked = true;
                    }
                    break;
                case 4:
                    if(columnHeights[position] < heightThreshold && blockPicked){
                        columnHeights[position] += 1;
                        blockPicked = false;
                    }
                    break;
                default:
                    break;
            }
        
        }
    }

        for(int  i = 0; i < numStacks; i++)
            std::cout<<columnHeights[i]<<" ";
        

    return 0;
}