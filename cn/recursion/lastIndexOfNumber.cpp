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

int lastIndex(int input[], int size, int x)
{
    if (size == 1)
    {
        return (input[0] == x) ? 0 : -1;
    }
    int ans = lastIndex(input + 1, size - 1, x);
    if (ans >= 0)
    {
        return ans + 1;
    }
    else
    {
        return (input[0] == x) ? 0 : -1;
    }
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << lastIndex(input, n, x) << endl;
    return 0;
}