/*Problem
Bob has an account in the Bobby Bank. His current account balance is w rupees.

Each month, the office in which Bob works deposits a fixed amount of x rupees to his account.
y rupees is deducted from Bob's account each month as bank charges.

Find his final account balance after z months. Note that the account balance can be negative as well.

Input Format
The first line will contain T, the number of test cases. Then the test cases follow.
Each test case consists of a single line of input, containing four integers W,X,Y, and Z — the initial amount, the amount deposited per month, the amount deducted per month, and the number of months.
Output Format
For each test case, output in a single line the final balance in Bob's account after Z months.
*/



#include <iostream>
using namespace std;

int main() {

    int t;
    cin>>t;


    for(int i = 0; i < t; i++){

        int w,x,y,z;
        cin>>w>>x>>y>>z;

        cout<<w+(x-y)*z<<endl;
    }




	return 0;
}
