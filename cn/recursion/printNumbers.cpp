/*
Print Numbers

Write a program to print numbers from 1 to n in increasing order recursively.

Input Format :
    Integer n

Output Format :
    Numbers from 1 to n (separated by space)

Constraints :
    1 <= n <= 10000

Sample Input 1 :
    6

Sample Output 1 :
    1 2 3 4 5 6

Sample Input 2 :
    4

Sample Output 2 :
    1 2 3 4
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

void print(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print(n - 1);
    cout << n << " ";
}
int main()
{
    int n;
    cin >> n;
    print(n);

    return 0;
}