/*
Find length of a string using recursion

Input Format :
    String S

Output Format :
    Integer representing length of string

Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.

Sample input 1:
    abcde

Sample output1:
    5

Sample input 2:
    ILoveIndia

Sample output 2:
    10
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