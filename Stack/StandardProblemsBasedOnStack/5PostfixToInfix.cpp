#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char x){
    return ((x>='a' && x<='z')||(x>='A' && x<='Z'));
}

string getInfix(string expression){
    stack<string> s;

    for(int i=0; i<expression.length(); i++){
        if(isOperand(expression[i])){
            s.push(string(1,expression[i]));
        }else{
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();

            string temp = "(" + op2 + expression[i] + op1 + ")";
            s.push(temp);
        }
    }

    return s.top();
}

int main(){
    string exp = "ab*c+"; 
    cout << getInfix(exp); 
    return 0;
}