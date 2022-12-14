#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string expression)
{
    // Write your code here
    stack<char> s;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(')
        {
            s.push('(');
        }
        else
        {
            if (s.size() > 0 && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.size() == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
    return 0;
}