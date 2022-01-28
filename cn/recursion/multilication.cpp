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

int multiplyNumbers(int m, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = multiplyNumbers(m, n - 1);
    ans = ans + m;
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    cout << multiplyNumbers(m, n) << endl;
    return 0;
}