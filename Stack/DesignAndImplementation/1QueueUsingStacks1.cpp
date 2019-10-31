#include<iostream>
#include<stack>

using namespace std;

struct Queue{
    stack<int> s1, s2;

    void enqueue(int x){
        if(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        } 
    }

    int dequeue(){
        if(!s1.empty()){
            cout << "Q is Empty"; 
            exit(0);
        }
    }
};

int main(){

    return 0;
}