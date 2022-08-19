#include<iostream>
#include<vector>

using namespace std;

#define Element int

void swap(Element &i, Element &j){
    Element temp = i;
    i = j;
    j = temp;
}


void quickSort(vector<int> & numbers, Element left, Element right){
    if(left >= right)
        return;
    int pivot = (left + right)/2;
    swap(numbers[pivot], numbers[right]);
    int pivotElement = numbers[right];
    Element j = left;
    for(Element i = left; i < right; i++){
        if(numbers[i] < pivotElement){
            swap(numbers[i], numbers[j]);
            j+=1;
        }
    }
    swap(numbers[right], numbers[j]);
    quickSort(numbers, left, j - 1);
    quickSort(numbers, j+1, right);
}


int pairs_absolute_sum(vector<int> & numbers, Element n, int k){
    Element pairs = 0;

    // sort the array first
    quickSort(numbers, 0, n-1);
    // for(Element i = 0; i < n; i++){
        // cout<<numbers[i]<<std::endl;
    // }
    for(Element i = 0; i < n; i++){
        for(Element j = 0 ; j < n; j++){
            if( (numbers[j] - numbers[i]) >= k){
                pairs += (n - j);
                break;
            }
        }
    }
    return pairs;
}


int main(){


    Element n;
    int k;
    cin>>n>>k;
    int temp;
    vector<int> numbers;
    for(Element i = 0; i < n; i++){
        cin>>temp;
        numbers.push_back(temp);
    }
    cout<<pairs_absolute_sum(numbers, n, k)<<endl;

    return 0;
}