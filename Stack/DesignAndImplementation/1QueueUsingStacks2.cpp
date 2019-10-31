#include<iostream>
#include<stack>

using namespace std;

struct Queue{
    stack<int> s1, s2;

    void enqueue(int x){
        s1.push(x);
    }

    int dequeue(){
        if (s1.empty() && s2.empty()) { 
            cout << "Q is empty"<<endl; 
            return -1; 
        } 

        if(s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main(){

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    cout << queue.dequeue() << '\n'; 
    cout << queue.dequeue() << '\n'; 
    cout << queue.dequeue() << '\n';

    return 0;
}