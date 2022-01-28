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