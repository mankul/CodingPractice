// another implementation of catalin numbers. in ../../combintorics/catalin.md
//
#include<iostream>
#include<map>

using namespace std;


int allTrees(int num, map<int, int> & countTrees){
    if(countTrees.find(num) != countTrees.end())
        return countTrees[num];
    int sum = 0;
    if(num == 0)
        sum = 1;
    else if (num == 1)
        sum = 1;
    else{
        for(int i = 0; i < num; i++){
            int left = allTrees(i, countTrees);
            int right = allTrees(num - 1 - i, countTrees);
            sum += left*right;
        }
    }
    countTrees[num] = sum;
    return countTrees[num];
}

int main(){

    // assuming a node as root and i and n - 1 - i as the two subtrees.


    int num;
    cin>>num;
    map<int, int> countTrees;
    cout<<allTrees(num, countTrees)<<endl;





    return 0;


}
