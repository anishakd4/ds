/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all
possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.

Input format :
    A numeric string S

Output Format :
    All possible codes in different lines

Constraints :
    1 <= Length of String S <= 10

Sample Input:
    1123

Sample Output:
    aabc
    kbc
    alc
    aaw
    kw
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

void printAllPossibleCodesHelper(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << endl;
        return;
    }

    char c1 = (input[0] - 48) + 96;
    printAllPossibleCodesHelper(input.substr(1), output + c1);

    if (input.size() > 1)
    {
        int d = (input[0] - 48) * 10 + (input[1] - 48);
        if (d <= 26)
        {
            char c2 = 96 + d;
            printAllPossibleCodesHelper(input.substr(2), output + c2);
        }
    }
}

void printAllPossibleCodes(string input)
{
    printAllPossibleCodesHelper(input, "");
}

int main()
{
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}