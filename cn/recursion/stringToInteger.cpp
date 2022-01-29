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

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

int stringToNumber(char input[], int len)
{
    if (len == 0)
    {
        return input[0] - '0';
    }
    int ans = stringToNumber(input + 1, len - 1);
    int a = input[0] - '0';
    a = a * pow(10, len);
    return a + ans;
}

int stringToNumber(char input[])
{
    return stringToNumber(input, length(input) - 1);
}
int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    return 0;
}
