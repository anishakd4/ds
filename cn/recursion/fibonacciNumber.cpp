/*
Calculate nth fibonacci number.

The Fibonacci numbers are the numbers in the following integer sequence.
    0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, ....

In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation
    Fn = Fn-1 + Fn-2

with seed values
    F0 = 0 and F1 = 1.

Input Format:
    A single integer ‘N’

Output Format:
    A single integer representing nth fibonacci number

Constraints:
    1 <= N <= 10^5

Sample Input :
    n = 2

Sample Output :
    1

Sample Input :
    n = 9

Sample Output :
    34
*/
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

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }

    if (n == 1)
    {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int i;
    cin >> i;
    cout << fib(i) << endl;
    return 0;
}