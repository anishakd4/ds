/*
Check Palindrome recursively


Check whether a given String S is a palindrome using recursion. Return true or false.


Input Format :
    String S

Output Format :
    'true' or 'false'

Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.

Sample Input 1 :
    racecar

Sample Output 1:
    true

Sample Input 2 :
    ninja

Sample Output 2:
    false
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
    // Write your code here
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