/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
    a. The string begins with an 'a'
    b. Each 'a' is followed by nothing or an 'a' or "bb"
    c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.

Input format :
    String S

Output format :
    'true' or 'false'

Constraints :
    1 <= |S| <= 1000
    where |S| represents length of string S.

Sample Input 1 :
    abb

Sample Output 1 :
    true

Sample Input 2 :
    abababa

Sample Output 2 :
    false

Explanation for Sample Input 2
    In the above example, a is not followed by either "a" or "bb", instead it's followed by "b" which results in false to be returned.
*/
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
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}