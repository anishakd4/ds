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

bool checkABHelper(char input[], int start)
{
    if (input[start] == '\0')
    {
        return true;
    }
    if (input[start] != 'a')
    {
        return false;
    }
    if (input[start + 1] != '\0' && input[start + 2] != '\0')
    {
        if (input[start + 1] == 'b' && input[start + 2] == 'b')
        {
            return checkABHelper(input, start + 3);
        }
    }
    return checkABHelper(input, start + 1);
}

bool checkAB(char input[])
{
    return checkABHelper(input, 0);
}

int main()
{
    char input[100];
    cin >> input;
    bool ans;
    ans = checkAB(input);
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}