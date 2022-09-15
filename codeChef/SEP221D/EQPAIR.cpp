/*roblem
You are given an array AA of length NN.

A pair (i, j)(i,j) (1\le i\lt j \le N)(1≤i<j≤N) is said to be good if gcd(A_i, A_j) = lcm(A_i, A_j)gcd(A 
i
​
 ,A 
j
​
 )=lcm(A 
i
​
 ,A 
j
​
 ). Here gcdgcd denotes the greatest common divisor and lcmlcm denotes least common multiple.

Find the total number of good pairs present in the given array.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
The first line of each test case contains an integer NN - the length of the array AA.
The second line of each test case contains NN space-separated integers A_1,A_2,\ldots,A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
 .
Output Format
For each test case, output on a new line the total number of such good pairs possible in the given array.

Constraints
1 \leq T \leq 1001≤T≤100
1 \leq N \leq 10^51≤N≤10 
5
 
1 \leq A_i \leq 10^91≤A 
i
​
 ≤10 
9
 
The sum of NN over all test cases won't exceed 3 \cdot 10^53⋅10 
5
 .*/


#include <iostream>
#include<vector>
using namespace std;



void swap(long &a, long &b){
    long temp = a;
    a = b;
    b = temp;
}



void quickSort( vector<long> & arr , int left, int right)
{

    if(left>= right)
        return;

    int pivot = (left + right)/2;
    swap(arr[right], arr[pivot]);
    int i = left;
    int j = left;
    while(i < right ){
        if(arr[i] < arr[right]){
            swap(arr[i], arr[j]);
            j+=1;
        }
        i+=1;
    }
    swap(arr[right], arr[j]);

    quickSort(arr, left, j-1);
    quickSort(arr, j+1, right);
    
}



int main() {


    int test;
    cin>>test;
    for(int i = 0; i < test; i++){
        int  n;
        cin>>n;
        vector<long> arr(n);
        int numbers;
        for(int j = 0 ; j < n; j++ ){
            cin>>arr[j];
        }

        quickSort(arr, 0, n-1);
        int leftIndex = 0;
        long long pairs = 0;
        for(int j = 0; j < n; j++)
        {
            if(arr[j] != arr[leftIndex]){
                numbers = j - leftIndex;
                pairs += ( numbers * (numbers - 1) )/2;
                leftIndex = j;
            }
        }
        if(arr[leftIndex] == arr[n-1]){
            numbers = n - leftIndex;
            pairs +=  ( numbers * (numbers - 1) )/2;
        }
        cout<<pairs<<endl;
    }

 	// your code goes here
	return 0;
}
