#include<iostream>
using namespace std;

int main(){


    int n;
    cin>>n;
    // 1 ( ----  2 )


    // Assumption, well bracketed sequnce is provided

    int num;
    int max_depth = 0;

    int max_current_depth = 0;
    int current_depth = 0;
    
    int max_depth_length = 0;

    int max_depth_length_index = 0;

    int left_index = 0;
    int right_index = 0;

    int first_position_max_depth = 0;

    int first_position_depth = 0;

    for(int i = 0; i < n ; i++){
        cin>>num;
        // if(bracket_stack.empty()){
            // cout<<"stack empty";
        // }
        if(num == 1) // insert to stack
        {
            current_depth += 1;
            if(current_depth > max_current_depth){
                max_current_depth = current_depth;
                first_position_depth = i;
            }
        }
        else{
            current_depth -= 1;
        }


        // Assumption: sequence is well versed. So we don;t need to check whether current depth 0 may not be stack empty
        if(current_depth == 0){
            right_index = i;
            if(max_current_depth > max_depth){
                max_depth = max_current_depth;
                max_depth_length_index =  left_index + 1;
                max_depth_length = right_index - left_index + 1;
                first_position_max_depth = first_position_depth + 1;
            }
            else if(max_current_depth == max_depth){
                if( (right_index - left_index + 1) > max_depth_length){
                    max_depth_length = right_index - left_index + 1;
                    max_depth_length_index = left_index + 1;
                }
            }
            max_current_depth = 0;
            left_index = i + 1;

        }

    }


    cout<<max_depth<<" "<<first_position_max_depth<<" "<<max_depth_length<<" "<<max_depth_length_index<<endl;
    return 0;
}