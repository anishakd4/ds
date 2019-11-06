#include<iostream>
#include<stack>

using namespace std;

stack<int> sortStack(stack<int> &st){
    stack<int> tmpStack;

    while(!st.empty()){
        int x = st.top();
        st.pop();

        while(!tmpStack.empty() && x < tmpStack.top()){
            st.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(x);
    }

    return tmpStack;
}

void printStack(stack<int> st){
    cout<<"Stack: "<<endl; 
    while(!st.empty()) { 
        int p=st.top(); 
        cout<<p<<" ";
        st.pop(); 
    } 
    cout<<endl;
}

int main(){

    stack<int> st;

    st.push(34); 
    st.push(3); 
    st.push(31); 
    st.push(98); 
    st.push(92); 
    st.push(23);

    stack<int> tmpStack = sortStack(st);

    printStack(tmpStack);

    return 0;
}