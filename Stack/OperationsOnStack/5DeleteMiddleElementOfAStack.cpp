#include<iostream>
#include<stack>

using namespace std;

void printStack(stack<char> st){
    cout<<"Stack: "<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void deleteMid(stack<char> &st, int mid){

    if(mid == 0){
        st.pop();
        return;
    }
    
    int x = st.top();
    st.pop();

    deleteMid(st, mid-1);
    st.push(x);
}

int main(){
    stack<char> st;

    st.push('1'); 
    st.push('2'); 
    st.push('3'); 
    st.push('4'); 
    st.push('5'); 
    st.push('6'); 
    st.push('7');

    printStack(st);

    int mid = st.size()/2;

    deleteMid(st, mid);

    printStack(st);

    return 0;
}