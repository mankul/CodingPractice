#include<iostream>
#include<vector>

using namespace std;


int lcs(int i, int j, int n,  int m, string A, string B, vector<vector<string> > & opt)
{

    if(i == n || j == m){
        return 0;
    }
    if(opt[i][j] != "" )
        return opt[i][j].length();

    if(A[i] == B[j]){
        int lengthArr = lcs(i+1, j+1, n, m, A, B, opt);
        if(lengthArr != 0)
            opt[i][j] = A[i] + opt[i+1][j+1];
        else
            opt[i][j] = A[i];
    }
    else{
        int max1 = lcs(i+1, j, n, m, A, B, opt);
        int max2 = lcs(i, j+1, n, m, A, B, opt);
        opt[i][j] = max1 > max2 ? opt[i+1][j] : opt[i][j+1];
    }

return opt[i][j].length();

}


int main(){
    string A;
    string B;

    cin>>A>>B;
    int n, m;
    n = A.length();
    m = B.length();
    vector<vector<string> > opt(n, vector<string> (m, ""));
    int i = 0;
    int j = 0;

    //using recursion

    cout<<lcs(i, j, n, m, A, B, opt)<<"\t"<<opt[0][0]<<endl;




    return 0;

}