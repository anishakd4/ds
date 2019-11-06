#include<iostream>
#include<stack>

using namespace std;

void insertAtBottom(stack<int> &st, int x){
    if(st.size() == 0){
        st.push(x);
    }else{
        int a = st.top();
        st.pop();
        insertAtBottom(st, x);
        st.push(a);
    }
}

void reverse(stack<int> &st){
    if(st.size() > 0){
        int x = st.top();
        st.pop();
        reverse(st); 
        insertAtBottom(st, x);
    }
}

int main(){
    stack<int> st;

    st.push(1); 
    st.push(2); 
    st.push(3); 
    st.push(4); 

    // cout<<"Reversed Stack"<<endl; 
    // while(!st.empty()) { 
    //     int p=st.top(); 
    //     cout<<p<<" ";
    //     st.pop(); 
    // } 
    // cout<<endl;

    reverse(st); 

    cout<<"Reversed Stack"<<endl; 
    while(!st.empty()) { 
        int p=st.top(); 
        cout<<p<<" ";
        st.pop(); 
    } 
    cout<<endl;

    return 0;
}