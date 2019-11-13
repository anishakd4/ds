#include<iostream>
#include<stack>

using namespace std;

struct Queue{
    stack<int> st;

    void enqueu(int x){
        st.push(x);
    }

    int dequeue(){
        if(st.empty()){
            cout<<"Queue is empty"<<endl;
            exit(0);
        }

        int x = st.top();
        st.pop();

        if(st.empty()){
            return x;
        }

        int item = dequeue();

        st.push(x);

        return item;
    }
};

int main(){
    Queue q;

    q.enqueu(1); 
    q.enqueu(2); 
    q.enqueu(3); 
  
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 

    return 0;
}