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

int length(char str[])
{
    if (str[0] == '\0')
    {
        return 0;
    }
    return 1 + length(str + 1);
}

int main()
{
    char str[100];
    cin >> str;
    int len = length(str);
    cout << len << endl;
    return 0;
}