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

void removeConsecutiveDuplicates(char str[])
{
    if (str[0] == '\0' || str[1] == '\0')
    {
        return;
    }
    if (str[0] == str[1])
    {
        int i = 0;
        while (str[i] != '\0')
        {
            str[i] = str[i + 1];
            i++;
        }
        removeConsecutiveDuplicates(str);
        str[i - 1] = '\0';
    }
    else
    {
        removeConsecutiveDuplicates(str + 1);
    }
}

int main()
{
    char str[1000000];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str << endl;
    return 0;
}