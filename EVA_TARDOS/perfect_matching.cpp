#include<iostream>
#include<vector>
#include<fstream>
#include<string>

using namespace std;

// preference list

void readFile(string filename, vector<vector<int>> & person){
    ifstream pref(filename);
    string stream;   
    if(pref.is_open()){
        while(pref){
            getline(pref, stream);
            cout<< "line is "<< stream;
        }
	cout<<endl;
    }
}



int main(){
int n;
cout<<"enter size of matching:"<<endl;
cin>>n;

vector<vector<int>> men(n, vector<int>(0));
vector<vector<int>> women(n, vector<int>(0));

string filename_men="./men_preference_list.txt";
string filename_women="./women_preference_list.txt";

readFile(filename_men, men);

return 0;
}
