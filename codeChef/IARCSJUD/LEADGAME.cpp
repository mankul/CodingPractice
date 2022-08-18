#include <iostream>
using namespace std;

int main() {
    
    int test_cases;
    int suml, sumr, n;
    int leadr, leadl;
    // for(int t = 0; t< test_cases; t++){
        suml = sumr = 0;
        leadl = leadr = 0;
        int x, y;
        int max_lead_left = 0, max_lead_right = 0;
        int lead;
        cin>>n;
        
        for(int i = 0; i < n; i++){
            cin>>x>>y;
            suml+=x;
            sumr+=y;
            if (sumr > suml){
                lead = sumr - suml;
                if (lead > max_lead_right)
                    max_lead_right = lead;
                leadr += lead;
            }
            else{
                lead = suml - sumr;
                if (lead > max_lead_left)
                    max_lead_left = lead;
                leadl += lead;
            }
        }
        if (leadl > leadr)
            cout<<"1 "<<max_lead_left<<endl;
        else
            cout<<"2 "<<max_lead_right<<endl;
    // }
	// your code goes here
	return 0;
}
