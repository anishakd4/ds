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

int power(int x, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (x * power(x, n - 1));
}

int main()
{
    int x, n;
    cin >> x >> n;
    cout << power(x, n) << endl;
    return 0;
}