#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
// climits for INT_MIN
#include <unordered_map>
using namespace std;
#include "StackUsingArray.cpp"
int main()
{
    // StackUsingArray s(4);
    StackUsingArray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.size() << endl;
    cout << s.top() << endl;

    cout << s.pop() << endl;

    cout << s.top() << endl;
    cout << s.size() << endl;

    cout << s.isEmpty() << endl;

    return 0;
}