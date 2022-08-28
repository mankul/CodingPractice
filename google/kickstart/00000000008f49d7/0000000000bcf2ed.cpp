/*
 * [200~Isyana is given the number of visitors at her local theme park on N consecutive days. The number of visitors on the i-th day is Vi. A day is record breaking if it satisfies both of the following conditions:
 *
 * Either it is the first day, or the number of visitors on the day is strictly larger than the number of visitors on each of the previous days.
 * Either it is the last day, or the number of visitors on the day is strictly larger than the number of visitors on the following day.
 * Note that the very first day could be a record breaking day!
 * Please help Isyana find out the number of record breaking days.
 *
 * Input
 * The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing the integer N. The second line contains N integers. The i-th integer is Vi and represents the number of visitors on the i-th day.
 *
 * Output
 * For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the number of record breaking days.
 *
 * Limits
 * Time limit: 20 seconds.
 * Memory limit: 1 GB.
 * 1≤T≤100.
 * 0≤Vi≤2×105, for all i.
 * Test Set 1
 * 1≤N≤1000.
 * Test Set 2
 * 1≤N≤2×105, for at most 10 test cases.
 * For the remaining cases, 1≤N≤1000.4
Sample Input:
4
8
1 2 0 7 2 0 2 0
6
4 8 15 16 23 42
9
3 1 4 1 5 9 2 6 5
6
9 9 9 9 9 9

Sample Output
save_alt
content_copy
Case #1: 2
Case #2: 1
Case #3: 3
Case #4: 0
 */




#include<iostream>
#include<vector>

using namespace std;



int main(){


    int t, n, number, prev, count;
    cin>>t;
    for(int test = 0; test < t; test++){
        cin>>n;
        int maxPrev = -1;
        bool isFlagMax = true;
        prev = -1;
        count  = 0;
        for(int i = 0; i < n; i++){
            cin>>number;
            
            if(i == 1){
                if(number < prev){
                    count += 1;
                    cout<<":"<<i<<endl;
                }
            else if( i == n-1 ){
                    if(number > maxPrev){
                    cout<<":"<<i<<endl;
                        count + = 1;
                    }
            }
            else{
                if( (number < prev) && (prev >= maxPrev) && isFlagMax ){
                    cout<<":"<<i<<endl;
                    count += 1;
                }
            }

            if(number > maxPrev){
                maxPrev = number;
                isFlagMax = true;
            }
            else if(number == maxPrev){
                isFlagMax = false;
            }
            
            prev = number;
        }

        cout<<"Case #"<<test<<": "<<count<<endl;
    
    }

    



    return 0;
}



