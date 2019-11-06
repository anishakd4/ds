#include<iostream>
#include<stack>

using namespace std;

int evaluatePostfix(string expresion){
    stack<char> st;

    for(int i=0; i<expresion.length(); i++){
        if(st.empty()){
            st.push(expresion[i]);
        }
        if(isdigit(expresion[i])){
            st.push(expresion[i] - '0');
        }else{
            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (expresion[i])  {  
                case '+': st.push(val2 + val1); break;  
                case '-': st.push(val2 - val1); break;  
                case '*': st.push(val2 * val1); break;  
                case '/': st.push(val2 / val1); break;  
            } 
        }
    }

    return st.top();
}

int main(){

    string expression = "231*+9-";

    cout<<"postfix evaluation: "<< evaluatePostfix(expression)<<endl;

    return 0;
}