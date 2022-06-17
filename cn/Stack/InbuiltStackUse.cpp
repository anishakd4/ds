#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
#include <stack>
// climits for INT_MIN
#include <unordered_map>
using namespace std;
int main()
{
    stack<int> s1;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    cout << s1.size() << endl;
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    return 0;
}