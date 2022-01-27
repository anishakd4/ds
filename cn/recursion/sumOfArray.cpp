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

int sum2(int input[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (input[0] + sum2(input + 1, n - 1));
}

int sum(int input[], int n)
{
    if (n == 1)
    {
        return input[0];
    }
    return (input[0] + sum(input + 1, n - 1));
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

    cout << sum(input, n) << endl;
    cout << sum2(input, n) << endl;
    return 0;
}