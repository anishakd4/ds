#include<iostream>
#include<stack>

using namespace std;

bool areParanthesisBalanced(string expression){
    stack<char> st;

    for(int i=0; i<expression.length(); i++){
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{'){
            st.push(expression[i]);
        }
        if(st.empty()){
            return false;
        }

        char x;
        switch (expression[i]){
            case ')':
                x = st.top();
                if(x != '('){
                    return false;
                }
                st.pop();
                break;
            
            case '}':
                x = st.top();
                if(x != '{'){
                    return false;
                }
                st.pop();
                break;
            
            case ']':
                x = st.top();
                if(x != '['){
                    return false;
                }
                st.pop();
                break;
        }
    }

    return (st.empty());
}

int main(){

    string expression = "{()}[]";

    if(areParanthesisBalanced(expression)){
        cout<<"Balanced"<<endl;
    }else{
        cout<<"Not balanced"<<endl;
    }

    return 0;
}