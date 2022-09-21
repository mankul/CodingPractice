#include<iostream>
#include<vector>

using namespace std;


typedef struct HeapNode{
    int val;    
} node;

void adjustHeap(vector<node> & heap){
    int size =  heap.size();
    shuffleMinHeap(heap, size-1);
}


int getLeft(int i){
    return 2 * i + 1;
}

int getRight(int i){
    return 2 * i  + 2;
}

int getParent(int i){
    return (i - 1)/2;
}


void swap(node & a, node &b){
    node temp = a;
    a = b;
    b = temp;
}

void shuffleMinHeap(vector<node> & heap, int position){
    int parent = getParent(position);
    if(parent >= 0){
        if(heap[position].val < heap[parent].val){
            swap(heap[position], heap[parent]);
            shuffleMinHeap(heap, parent);
        }
    }
}

void insertIntoMinHeap(vector<node> & heap, int number){
    node newNode;
    newNode.val = number;
    heap.push_back(newNode);
    int sizeNode = heap.size();
    int position = sizeNode - 1;
}


int main(){


    int n;
    cin>>n;
    vector<node> heap;
        
    int num;

    for(int i = 0; i < n; i++){
        cin>>num;
        node newNode;
        newNode.val = num;
        heap.push_back(newNode);
        adjustHeap(heap);
    }


    return 0;
}