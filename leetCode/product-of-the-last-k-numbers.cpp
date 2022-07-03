/*
Design an algorithm that accepts a stream of integers and 
retrieves the product of the last k integers of the stream.

Implement the ProductOfNumbers class:

ProductOfNumbers() Initializes the object with an empty stream.
void add(int num) Appends the integer num to the stream.
int getProduct(int k) Returns the product of the last k numbers in the current list. 
You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, 
the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.
*/

#include<iostream>
#include<vector>


using namespace std;

class ProductOfNumbers {
public:
    
    vector<int> numberStream;
    int last_size = 0;
    int last_k=0;
    long multiple=1;
    
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        numberStream.push_back(num);
    }
    
    int getProduct(int k) {
        int size = numberStream.size();
        // int product = 1;
        // for(int i = size - k; i < size; i ++){
        //     product *= numberStream[i];
        // }
        if( k > last_k){
            for(int i = size - k; i < size - (last_k+1); i++)   
                multiple*=numberStream[i];
        }
        else if( k < last_k){
            for(int i = size - (last_k+1); size - k; i++){
                multiple/=numberStream[i];
            }
        }
        else{
            multiple/=numberStream[size-k];
        }
        multiple *= numberStream[size-1];
        last_k=k;
        return multiple;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

int main(){


    ProductOfNumbers * prod = new ProductOfNumbers();
    prod->add(3);
    prod->add(4);
    prod->add(5);
    cout<<prod->getProduct(3)<<endl;
    prod->add(1);
    prod->add(0);
    cout<<prod->getProduct(3)<<endl;
    prod->add(10);
    prod->add(10);
    prod->add(10);
    prod->add(10);
    cout<<prod->getProduct(4)<<endl;
    for(int i = 0; i < prod->numberStream.size();i++)
        cout<<prod->numberStream[i]<<endl;

}