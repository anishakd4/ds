#include<iostream>
#include<queue>

using namespace std;

class Stack{
    int count;
    priority_queue<pair<int,int> > pq;

    public:
        void push(int x){
            count++;
            pq.push(pair<int, int>(count, x));
        }

        void pop(){
            if(pq.empty()){
                cout<<"Nothing to pop"<<endl;
            }
            count--;
            pq.pop();
        }

        int top(){
            pair<int, int> temp = pq.top();
            return temp.second;
        }

        bool isEmpty(){
            return pq.empty();
        }
};

int main(){

    Stack* s = new Stack();

    s->push(1);
    s->push(2);
    s->push(3);

    while(!s->isEmpty()){
        cout<<s->top()<<endl;
        s->pop();
    }
    
    return 0;
}