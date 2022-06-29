/*
Return all the subsequences of a string

Input Format:
    A string

Output Format:
    Print all the subsequences of a string in different lines

Input :
    abc

Output :
    ""
    a
    b
    c
    ab
    bc
    ac
    abc
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

int subs(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallString = input.substr(1);
    int smallOutputSize = subs(smallString, output);
    for (int i = 0; i < smallOutputSize; i++)
    {
        output[i + smallOutputSize] = input[0] + output[i];
    }
    return 2 * smallOutputSize;
}

int main()
{
    /*
    abc ["", a, b, c, ab, bc, ac, abc]

    pow(2, n) is total number of subsequences.

    As for every character we have to make
    a choice whether to include or not
    include the character.

    difference between subsequences and substrings:
    substrings are continuous.
    For subsequences we can pick any characters
    */

    string input;
    cin >> input;
    int x = pow(2, input.size());

    string *output = new string[x];
    int count = subs(input, output);

    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}