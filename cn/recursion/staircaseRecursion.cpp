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

int staircase(int n)
{
    if (n == 0)
    {
        return 1;
    }
    if (n < 1)
    {
        return 0;
    }
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}
int main()
{
    int n, output;
    cin >> n;
    output = staircase(n);
    cout << output << endl;
    return 0;
}