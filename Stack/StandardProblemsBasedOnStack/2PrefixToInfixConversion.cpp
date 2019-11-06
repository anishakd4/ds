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

string preToInfix(string expression){
    stack<string> s;

    for(int i=expression.length() - 1; i>=0; i--){
        if(isOperator(expression[i])){
            
            string op1 = s.top();
            s.pop();

            string op2 = s.top();
            s.pop();
            
            string temp = "(" + op1 + expression[i] + op2 + ")";

            s.push(temp);
        }else{
            s.push(string(1, expression[i]));
        }
    }

    return s.top();
}

int main(){
    
    string expression = "*-A/BC-/AKL"; 
    cout << "Infix : " << preToInfix(expression)<<endl;

    return 0;
}