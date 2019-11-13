#include<iostream>
#include<stack>

using namespace std;

struct Queue{
    stack<int> s1, s2;

    void enqueue(int x){
        s1.push(x);
    }

    int dequeue(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue emepty"<<endl;
            exit(0);
        }

        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s2.pop();
            }
        }

        int x = s2.top();
        s2.pop();
        return x;
    }
};

int main(){

}