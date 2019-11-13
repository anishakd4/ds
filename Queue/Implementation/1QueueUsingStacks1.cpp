#include<iostream>
#include<stack>

using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enqueue(int x){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue(){
        if(s1.empty()){
            cout<<"Queue empty"<<endl;
            exit(0);
        }
        int temp = s1.top();
        s1.pop();
        return temp;
    }
};

int main(){

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<"dequeue: "<<q.dequeue()<<endl;
    cout<<"dequeue: "<<q.dequeue()<<endl;
    cout<<"dequeue: "<<q.dequeue()<<endl;

    return 0;
}