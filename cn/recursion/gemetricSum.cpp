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