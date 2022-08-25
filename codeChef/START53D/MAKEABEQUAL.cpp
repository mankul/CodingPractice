#include <iostream>
#include<vector> 
using namespace std;

int main() {
	// your code goes here
	int t;
	int n1;
	long temp;
	cin>>t;
	for(int i = 0; i< t; i++){
	    cin>>n1;
	    vector<long> arr1;
	    vector<long> arr2;
	    
	    for(int j = 0; j< n1; j++){
	        cin>>temp;
	        arr1.push_back(temp);
	    }
	    for(int j = 0; j< n1; j++){
	        cin>>temp;
	        arr2.push_back(temp);
	    }
	    long suma = 0;
	    long sumb = 0;
	    for(int j = 0; j < n1; j++)
	        if((arr1[j] - arr2[j]) > 0)
	            suma += (arr1[j] - arr2[j]);
	        else
	            sumb += (arr2[j] - arr1[j]);
	    
	    if(suma - sumb)
	        cout<<"-1"<<endl;
	    else
	        cout<<suma<<endl;
	}
	return 0;
	    
	
}
