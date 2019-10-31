#include<iostream>
#include<stack>

using namespace std;

class SpecialStack{
    stack<int> min;
    stack<int> s;

    public:
        void push(int x);
        int pop();
        int getMin();
};

void SpecialStack::push(int x){
    if(s.empty()){
        s.push(x);
        min.push(x);
    }else{
        s.push(x);
        if(min.top() < x){
            min.push(min.top());
        }else{
            min.push(x);
        }
    }
}

int SpecialStack::pop(){
    int x = s.top();
    s.top();
    min.pop();

    return x;
}

int SpecialStack::getMin(){
    int x = min.top();
    return x;
}

int main(){

    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout<<s.getMin()<<endl; 
    s.push(5); 
    cout<<s.getMin()<<endl;

    return 0;
}