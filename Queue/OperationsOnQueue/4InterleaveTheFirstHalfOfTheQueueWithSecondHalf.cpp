#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void interLeaveQueue(queue<int> &q){

    if(q.empty()){
        return;
    }

    stack<int> st;

    int s = q.size()/2;

    for(int i=0; i<s; i++){
        st.push(q.front());
        q.pop();
    }

    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    for(int i=0; i<s; i++){
        q.push(q.front());
        q.pop();
    }

    for(int i=0; i<s; i++){
        st.push(q.front());
        q.pop();
    }

    for(int i=0; i<s; i++){
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }

}

void printQueue(queue<int> q){
    cout<<"Queue: "<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

int main(){

    queue<int> q; 

    q.push(11); 
    q.push(12); 
    q.push(13); 
    q.push(14); 
    q.push(15); 
    q.push(16); 
    q.push(17); 
    q.push(18); 
    q.push(19); 
    q.push(20); 

    printQueue(q);
    interLeaveQueue(q); 
    printQueue(q);

    return 0; 
}