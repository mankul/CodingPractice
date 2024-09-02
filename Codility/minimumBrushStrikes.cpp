// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl
//
//

#include<iostream>
#include<vector>




#define MAX_STROKES 1000000000
#define unit long long



using namespace std;

int main() {


    int num;
    cin>>num;
    vector<unit> A(num);
    for(int i = 0; i < num; i++)
	cin>>A[i];
    unit numberOfCounts = 0;
    // unit minPoint = MAX_STROKES;
    // bool paintLeft = true;
    // int leftPosition = 0;
    unit size = A.size();
    unit maxLimit  = 0;
    for(int i = 0; i < size; i++){
        if(A[i] > maxLimit)
            maxLimit = A[i];
    }
    // int limitLeft = 0;
    int stepCount = 0;
    for(int j = 0; j < maxLimit; j++){
        stepCount = 0;
        for(int i = 0; i < size; i++){
            if(A[i] != 0){
                if(i == size-1 || A[i+1] == 0)
                    stepCount += 1;
                A[i] -= 1;
            }
        }
        numberOfCounts += stepCount;
    }

    cout<< (numberOfCounts > MAX_STROKES ? -1 : numberOfCounts);
	return 0;

    // while(limitLeft < maxLimit){
    //     for(int i = 0; i < size; i++){
    //         if(A[i] == 0){
    //             if(i>0 && A[i-1] != 0){
    //                 for(int j = leftPosition ; j < i; j++){
    //                     A[j] -= minPoint;
    //                 numberOfCounts += minPoint;
    //                 minPoint = MAX_STROKES;
    //                 if(step < minPoint)
    //                     step  = minPoint;
    //                }
    //             }
    //         }
    //         else if(A[i] < minPoint){
    //             if(i == 0 || (i > 0 && A[i-1] == 0) )
    //                 leftPosition = i;
    //             minPoint = A[i];
    //         }
    //     }
    //     if(A[leftPosition] > 0){
    //         for(int i = leftPosition; i < size; i++){
    //             A[i] -= minPoint;
    //         }
    //         if(step < minPoint)
    //             step  = minPoint;
    //     }
    // }



    // write your code in C++14 (g++ 6.2.0)
}

