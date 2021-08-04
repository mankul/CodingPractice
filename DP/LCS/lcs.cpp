#include<iostream>
#include<vector>

#define MAXSIZE 30


using namespace std;

class Sequence{
    
    public:
        int length;
        string sequence;

    void calculate_length(){
        length = sequence.size();
    }
};



int find_LCS(string s1, string s2, int m, int n, vector<char> & result, char * tabulae, int len2){

    if(m == -1 || n == -1)
        return 0;

    if (*(tabulae + m * len2 + n ) != 0){
        return *(tabulae + m* len2 + n);
    }
    if(s1[m] == s2[n])
    {
        result.push_back(s1[m]);
        *(tabulae + len2 * m + n) = 1 + find_LCS(s1, s2, m-1, n-1, result, tabulae, len2);
        return *(tabulae + len2 * m + n);
    }
    else{
        int res1 = find_LCS(s1, s2, m-1, n, result, tabulae,  len2);
        int res2 = find_LCS(s1, s2, m, n-1, result, tabulae,  len2);
        return res1>res2?res1:res2;
    }
}

int main(){
    

    Sequence seq1;
    Sequence seq2;


    cin>>seq1.sequence>>seq2.sequence;
    seq1.calculate_length();
    seq2.calculate_length();
    // cout<<seq1.length;


    char tabulaue[seq1.length][seq2.length];
    for(int i = 0; i < seq1.length; i++)
        for(int j = 0; j < seq2.length; j++)
            tabulaue[i][j] = 0;

    vector<char> result;
    int res = find_LCS(seq1.sequence, seq2.sequence, seq1.length, seq2.length, result, (char     * )tabulaue, seq2.length );
    cout<<res<<endl;
    
    for(vector<char>::iterator it1 = result.begin(); it1 != result.end(); it1++ ){
        cout<<*it1<<"\t";
    }
    cout<<endl;
    
    





    // read lines
    // char * x = new char[MAXSIZE];
    // char * y = new char[MAXSIZE];
    // fgets(x, MAXSIZE, stdin);
    // fgets(y, MAXSIZE, stdin);
    // cout<<x;
    // cout<<y;


    // using string class
    // string x;
    // string y;
    // cin>>x>>y;
    // cout<<x<<y<<endl;

    return 0;
}