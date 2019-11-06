#include<iostream>
#include<stack>

using namespace std;

void reverseWords(string str){
    stack<char> st;

    for(int i=0; i<str.length(); i++){
        if(str[i] != ' '){
            st.push(str[i]);
        }else{
            while(!st.empty()){
                cout<<st.top();
                st.pop();
            }
            cout<<" ";
        }
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main(){
    string str = "Geeks for Geeks";
    reverseWords(str);

    return 0;
}