#include<iostream>
#include<stack>

using namespace std;

void sortedInsert(stack<int> &st, int x){
    if(st.empty() || x > st.top()){
        st.push(x);
        return;
    }

    int p = st.top();
    st.pop();
    sortedInsert(st, x);
    st.push(p);
}

void sortStack(stack<int> &st){
    if(!st.empty()){
        int x = st.top();
        st.pop();
        sortStack(st);

        sortedInsert(st, x);
    }
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

    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);

    printStack(st);

    sortStack(st);

    printStack(st);

    return 0;
}