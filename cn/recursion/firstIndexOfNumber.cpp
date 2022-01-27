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

int firstIndex(int input[], int size, int x)
{
    if (input[0] == x)
    {
        return 0;
    }

    if (size == 1)
    {
        return -1;
    }
    else
    {
        int an = firstIndex(input + 1, size - 1, x);
        if (an >= 0)
        {
            return an + 1;
        }
        else
        {
            return an;
        }
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

    cout << firstIndex(input, n, x) << endl;

    return 0;
}