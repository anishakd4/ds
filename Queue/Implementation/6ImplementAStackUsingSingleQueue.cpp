#include<iostream>
#include<queue>

using namespace std;

class Stack{
    queue<int> q;

    public:
        void push(int x){
            int s = q.size();

            q.push(x);

            for(int i=0; i<s; i++){
                q.push(q.front());
                q.pop();
            }
        }

        void pop(){
            if(q.empty()){
                cout<<"Stack empty"<<endl;
            }else{
                q.pop();
            }
        }

        int top(){
            return (q.empty() ? -1 : q.front());
        }

        bool empty(){
            return q.empty();
        }
};

int main(){

    Stack s;

    s.push(10); 
    s.push(20); 

    cout << s.top() << endl; 

    s.pop(); 
    s.push(30); 
    s.pop();
    
    cout << s.top() << endl;

    return 0;
}