/*
Geometric Sum

Given k, find the geometric sum using recursion. i.e.

1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

Input format :
    Integer k

Output format :
    Geometric sum (upto 5 decimal places)

Constraints :
    0 <= k <= 1000

Sample Input 1 :
    3

Sample Output 1 :
    1.87500

Sample Input 2 :
    4

Sample Output 2 :
    1.93750

Explanation for Sample Input 1:
    1+ 1/(2^1) + 1/(2^2) + 1/(2^3) = 1.87500
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

double geometricSum(int k)
{
    if (k < 0)
    {
        return 0;
    }

    double d = geometricSum(k - 1);

    double ans = d + (1 / (pow(2, k)));

    return ans;
}

int main()
{
    int k;
    cin >> k;
    cout << fixed << setprecision(5);
    cout << geometricSum(k) << endl;

    return 0;
}