/*
Given a string S, remove consecutive duplicates from it recursively.

Input Format :
    String S

Output Format :
    Output string

Constraints :
    1 <= |S| <= 10^3
    where |S| represents the length of string

Sample Input 1 :
    aabccba

Sample Output 1 :
    abcba

Sample Input 2 :
    xxxyyyzwwzzz

Sample Output 2 :
    xyzwz
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

void removeConsecutiveDuplicates(char *input)
{
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        int i = 0;
        while (input[i] != '\0')
        {
            input[i] = input[i + 1];
            i++;
        }
        removeConsecutiveDuplicates(input);
    }
    removeConsecutiveDuplicates(input + 1);
}

int main()
{
    char str[1000000];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str << endl;
    return 0;
}