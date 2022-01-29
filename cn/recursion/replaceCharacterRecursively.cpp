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

void charReplace(char str[], char c1, char c2)
{
    if (str[0] == '\0')
    {
        return;
    }
    if (str[0] == c1)
    {
        str[0] = c2;
    }
    charReplace(str + 1, c1, c2);
}
int main()
{
    char input[1000000];
    char c1, c2;
    cin >> input;
    cin >> c1 >> c2;
    charReplace(input, c1, c2);
    cout << input << endl;
    return 0;
}