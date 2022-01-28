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

bool helperpali(char input[], int start, int end)
{
    if (start > end)
    {
        return true;
    }

    if (input[start] != input[end])
    {
        return false;
    }

    return helperpali(input, start + 1, end - 1);
}

bool checkPalindrome(char input[])
{
    int length = 0;
    while (input[length] != '\0')
    {
        length++;
    }

    bool res = helperpali(input, 0, length - 1);

    return res;
}

int main()
{
    char input[50];
    cin >> input;

    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}