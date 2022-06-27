/*
Sum of digits (recursive)

Write a recursive function that returns the sum of the digits of a given integer.

Input format :
    Integer N

Output format :
    Sum of digits of N

Constraints :
    0 <= N <= 10^9

Sample Input 1 :
    12345

Sample Output 1 :
    15

Sample Input 2 :
    9

Sample Output 2 :
    9
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

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }

    int x = sumOfDigits(n / 10);
    int r = n % 10;
    int sum = r + x;

    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << sumOfDigits(n) << endl;
    return 0;
}