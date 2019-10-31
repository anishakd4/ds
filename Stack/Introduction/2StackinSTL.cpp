#include<iostream>
#include<stack>

using namespace std;

void showstack(stack<int> s){
    cout<<"Stack: "<<endl;
    while (!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main(){

    stack<int> s;

    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 

    showstack(s);

    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top();

    cout << "\ns.pop() : "<<endl;; 
    s.pop(); 

    showstack(s); 

    return 0;
}