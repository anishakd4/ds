#include<iostream>
#define MAX 1000
using namespace std;

class Stack{
    int top;

    public:
        int a[MAX];
        Stack(){
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool isEmpty();
};

bool Stack::push(int x){
    if (top >= (MAX - 1)) { 
        cout<<"Stack Overflow"<<endl; 
        return false; 
    } else { 
        top++; 
        a[top] = x;
        cout<<x<<" pushed into stack\n"; 
        return true; 
    } 
}

int Stack::pop(){
    if(top<0){
        cout<<"Stack underflow"<<endl;
        return 0;
    }else{
        top--;
        int x = a[top];
        return x;
    }
}

int Stack::peek(){
    if(top<0){
        cout<<"Stack is empty"<<endl;
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

int main(){
    class Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout<<stack.pop()<<" Popped from stack\n";

    return 0;
}