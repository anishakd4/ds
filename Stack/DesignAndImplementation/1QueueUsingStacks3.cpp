#include<iostream>
#include<stack>

using namespace std;

struct Queue{
    stack<int> s;

    void enqueue(int x){
        s.push(x);
    }

    int dequeue(){

        if(s.empty()){
            cout<<"Q is empty"<<endl;
            return -1;
        }
        int x = s.top();
        s.pop();

        if(s.empty()){
            return x;
        }

        int item = dequeue();

        s.push(x);

        return item;
    }
};

int main(){

    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n'; 
    cout << q.dequeue() << '\n';

    return 0;
}