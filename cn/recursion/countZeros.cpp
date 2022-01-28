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

int countZeros(int n)
{
    if (n / 10 == 0)
    {
        if (n % 10 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int x = countZeros(n / 10);
    int r = n % 10;
    if (r == 0)
    {
        return x + 1;
    }
    else
    {
        return x;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << countZeros(n) << endl;
    return 0;
}