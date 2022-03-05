// use sorting to sort the array, later do one iteration
// stl have inbuild merge method, we are using pointers 
// use heap sort for inline sorting in  /theta(n/log(n))
#include<iostream>

using namespace std;



int * heap_sort(int * arr, int start, int size){
    // array's first element is root of heap, next element is the left child and next to left
    // element is the right child node of the root node.
    // i -> i + 1, (i + end)/2
    for(int i = start; i < size; i++){
        // on ith iteration, assuming ith element insertion in the heap.
        int j = i;//(i%2 == 0)? i/2-1:i/2;
        int temp;
        while(j > 0){
            int k = (j%2 == 0)?j/2-1:j/2;
            if(arr[j] > arr[k]){
                temp = arr[j];
                arr[j] = arr[k];
                arr[k] = temp;
                j = k;
            }
            else{
                break;
            }      
            
        }
    }
    return arr;
}


int main(){

    int arr_count;
    cin>>arr_count;
    int arr[arr_count];
    int num;
    for(int i = 0; i < arr_count; i++){
        cin>>num;
        arr[i]=num;
    }
    int * new_arr = heap_sort(arr,0,arr_count);
    for(int i = 0;i < arr_count; i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
    
    return 0;
}

