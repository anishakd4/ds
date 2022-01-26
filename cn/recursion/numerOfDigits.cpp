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