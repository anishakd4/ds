/*
Number of Digits

Print the number of digits present in a number recursively.

Input Format :
    Integer n

Output Format :
    Count of digits

Constraints :
    1 <= n <= 10^6

Sample Input 1 :
    156

Sample Output 1 :
    3

Sample Input 2 :
    7

Sample Output 2 :
    1
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

int count(int n)
{
    if (n < 10)
    {
        return 1;
    }
    return 1 + count(n / 10);
}

int main()
{
    int n;
    cin >> n;

    cout << count(n) << endl;
    return 0;
}