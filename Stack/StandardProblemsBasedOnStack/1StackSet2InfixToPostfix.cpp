#include<iostream>
#include<stack>

using namespace std;

int prec(char c) { 
    if(c == '^') {
        return 3;
    }else if(c == '*' || c == '/') {
        return 2; 
    }else if(c == '+' || c == '-') {
        return 1;
    }else{
        return -1; 
    }
} 

void infixToPostfix(string expression){
    stack<char> s;
    string ns;

    for(int i=0; i<expression.length(); i++){
        if((expression[i] >= 'a' && expression[i] <= 'z') || (expression[i] >= 'A' && expression[i] <= 'Z')){
            ns = ns + expression[i];
        }else if(expression[i] == '('){
            s.push('(');
        }else if(expression[i] == ')'){
            while( s.size() > 0 && s.top() != '('){
                char c = s.top();
                s.pop();
                ns = ns + c;
            }
            s.pop();
        }else{
            while( s.size() > 0 && prec(expression[i]) <= prec(s.top())){
                char c = s.top();
                s.pop();
                ns = ns + c;
            }
            s.push(expression[i]);
        }
    }

    while(s.size() > 0) { 
        char c = s.top(); 
        s.pop(); 
        ns += c; 
    }

    cout<<ns<<endl;
}

int main(){

    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expression);
    return 0;
}