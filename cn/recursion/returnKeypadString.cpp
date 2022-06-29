/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n. Return empty string for numbers 0 and 1.
Note :
    1. The order of strings are not important.
    2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.

Input Format :
    Integer n

Output Format :
    All possible strings in different lines

Constraints :
    1 <= n <= 10^6

Sample Input:
    23

Sample Output:
    ad
    ae
    af
    bd
    be
    bf
    cd
    ce
    cf
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

string dial(int key)
{
    unordered_map<int, string> m;
    m[0] = "";
    m[1] = "";
    m[2] = "abc";
    m[3] = "def";
    m[4] = "ghi";
    m[5] = "jkl";
    m[6] = "mno";
    m[7] = "pqrs";
    m[8] = "tuv";
    m[9] = "wxyz";
    return m[key];
}

int keypad(int num, string output[])
{
    if (num < 10)
    {
        string str = dial(num);
        for (int j = 0; j < str.size(); j++)
        {
            output[j] = str[j];
        }
        return str.size();
    }
    int smallNum = num / 10;
    int smallOutputSize = keypad(smallNum, output);
    string str2 = dial(num % 10);
    for (int j = 1; j < str2.size(); j++)
    {
        for (int i = 0; i < smallOutputSize; i++)
        {
            output[j * smallOutputSize + i] = output[i];
        }
    }
    for (int j = 0; j < str2.size(); j++)
    {
        for (int i = 0; i < smallOutputSize; i++)
        {
            output[j * smallOutputSize + i] = output[j * smallOutputSize + i] + str2[j];
        }
    }
    return (str2.size() * smallOutputSize);
}
int main()
{
    int num;
    cin >> num;

    string output[100000];
    int count = keypad(num, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}