#include<iostream>
#include<stack>

using namespace std;

bool isOperator(char x) { 
    switch (x) { 
        case '+': 
        case '-': 
        case '/': 
        case '*': 
            return true; 
    } 
    return false; 
} 

string postToPre(string expression){
    
    stack<string> s;
    for(int i=0; i<expression.length(); i++){
        if(isOperator(expression[i])){

            string op1 = s.top();
            s.pop();

            string op2 = s.top();
            s.pop();

            string temp = expression[i] + op2 + op1;

            s.push(temp);
        }else{
            s.push(string(1, expression[i]));
        }
    }

    return s.top();
}

int main(){

    string expression = "ABC/-AK/L-*"; 
    cout << "Prefix : " << postToPre(expression)<<endl;

    return 0;
}