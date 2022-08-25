#include<iostream>
#include<vector>

using namespace std;



void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(vector<int> & chewCapacity, int left, int right){
    if(left >= right)
        return;
    int pivot = (left + right)/2;
    swap(chewCapacity[right], chewCapacity[pivot]);

    int i = 0,  j = 0;
    while(i < right){
        if(chewCapacity[i] < chewCapacity[right]){
            swap(chewCapacity[j], chewCapacity[i]);
            j++;
        }
        i++;
    }
    swap(chewCapacity[j], chewCapacity[right]);

    quickSort(chewCapacity, left, j-1);
    quickSort(chewCapacity, j + 1, right);

}



vector<int> mergeSort(vector<int> &chewCapacity, int left, int right){
    vector<int> sortedArray;
    if(left == right){
        sortedArray.push_back(chewCapacity[left]);
        return sortedArray;
    }
    
    int mid = (left + right)/2;
    vector<int> leftArray = mergeSort(chewCapacity, left, mid);
    vector<int> rightArray = mergeSort(chewCapacity, mid+1, right); 

    int length1 = leftArray.size();
    int length2 = rightArray.size();
    for(int i = 0, j = 0; ;){
        if(i == length1-1 && j == length2 -1 )
            break;
        else if(i == length1 - 1){
            sortedArray.push_back(rightArray[j]);
            j++;
        }
        else if(j == length2 -1){
            sortedArray.push_back(leftArray[i]);
            i++;
        }
        else{
            if(leftArray[i] > rightArray[j] )
            {
                sortedArray.push_back(rightArray[j]);
                j++;
            }
            else{
                sortedArray.push_back(leftArray[i]);
                i++;
            }
        }
    }
    
    return sortedArray;

}


int main(){

    int N;
    cin>>N;
    int K;
    cin>>K;
    vector<int> chewCapacity;
    int temp;
    for(int i = 0; i < N; i++){
        cin>>temp;
        chewCapacity.push_back(temp);
    }

    // quickSort(chewCapacity, 0, N-1);
    chewCapacity =  mergeSort(chewCapacity, 0 , N-1);

    long long sum = 0;

    for(int i = 0; i < N-1; i ++){
        int left = i+1;
        int right = N-1;
        int j = (left + right)/2;
        int restCapacity = K - chewCapacity[i];

        int foundIndex = i;

        while( j > i && j < N){
            if(restCapacity > chewCapacity[j])
                if(j == N-1){
                    foundIndex = N-1;
                    break;
                }
                else if(restCapacity <= chewCapacity[j+1] ){
                    foundIndex = j;
                    break;
                }
                else{
                    left = j + 1;
                    j = (left + right)/2;
                }
            else{
                if(restCapacity > chewCapacity[j-1]){
                    foundIndex = j-1;
                    break;
                }
                right = j-1;
                j = (left + right)/2;
            }
        }
        if(foundIndex != i)
            sum += (foundIndex - i);
    }
    cout<<sum<<endl;

    return 0;
}