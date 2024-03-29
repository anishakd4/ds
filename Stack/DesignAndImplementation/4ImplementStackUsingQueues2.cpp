#include<iostream>
#include<queue>

using namespace std;

class Stack{

    queue<int> q1, q2;
    int curr_size;

    public:
        Stack(){
            curr_size = 0;
        }

        void push(int x){
            q1.push(x);
            curr_size++;
        }

        void pop(){
            if(q1.empty()){
                return;
            }

            while (q1.size() != 1 ){
                q2.push(q1.front());
                q1.pop();
            }

            q1.pop();
            curr_size--;

            queue<int> q = q1;
            q1 = q2;
            q2 = q;
            
        }

        int top(){
            if(q1.empty()){
                return -1;
            }

            while (q1.size() != 1){
                q2.push(q1.front());
                q1.pop();
            }

            int x = q1.front();

            q1.pop();

            q2.push(x);

            queue<int> q = q1;
            q1 = q2;
            q2 = q;

            return x;
        }

        int size(){
            return curr_size;
        }

};

int main(){

    Stack s;
    s.push(1);  
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "current size: " << s.size() << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    cout << "current size: " << s.size() << endl; 
    return 0;
}