#include<iostream>
#include<stack>
// #include<string>

using namespace std;



void inpurChar(){
    int count;
    cin>>count;
    char arr[count];
    stack<char> st;
    for(int i = 0; i < count; i++){
        cin>>arr[i];
        if(st.empty())
            st.push(arr[i]);
        else{
            if( (st.top() == '[' && arr[i] == ']') || (st.top() == '(' && arr[i] == ')' ) || (st.top() == '{' && arr[i] == '}') )
                st.pop();
            else
                st.push(arr[i]);
        }
    }
    if(!st.empty())
        cout<<"not balanced"<<endl;
    else  
        cout<<"balanced "<<endl;

}

int main(){


    string str;
    cin>>str;
    stack<char> st;
    for(int i = 0; i < str.length(); i++){
        if( (str[i] == '}' && st.top() == '{') ||\
            (str[i] == ')' && st.top() == '(') ||\
            (str[i] == ']' && st.top() == '[') )
                st.pop();
        else
            st.push(str[i]);
    }
    if(st.empty())
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;

    return 0;
}