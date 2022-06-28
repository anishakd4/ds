/*
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Input format :
    String S

Output format :
    Modified string

Constraints :
    0 <= |S| <= 1000
    where |S| represents length of string S.

Sample Input 1 :
    hello

Sample Output 1:
    hel*lo

Sample Input 2 :
    aaaa

Sample Output 2 :
    a*a*a*a
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

int length(char input[])
{
    int len = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}

void pairStar(char input[], int start)
{
    if (input[start] == '\0' || input[start + 1] == '\0')
    {
        return;
    }
    pairStar(input, start + 1);
    if (input[start] == input[start + 1])
    {
        int len = length(input);
        for (int i = len - 1; i >= start + 1; i--)
        {
            input[i + 1] = input[i];
        }
        input[len + 1] = '\0';
        input[start + 1] = '*';
    }
}

void pairStar(char input[])
{
    pairStar(input, 0);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
    return 0;
}