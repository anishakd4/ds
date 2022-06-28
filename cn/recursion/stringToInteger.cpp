/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers,
you need to convert the string into corresponding integer and return the answer.

Input format :
    Numeric string S (string, Eg. "1234")

Output format :
    Corresponding integer N (int, Eg. 1234)

Constraints :
    0 <= |S| <= 9
    where |S| represents length of string S.

Sample Input 1 :
    00001231

Sample Output 1 :
    1231

Sample Input 2 :
    12567

Sample Output 2 :
    12567
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

int stringToNumber(char input[], int len)
{
    if (len == 1)
    {
        return (input[0] - '0');
    }
    int x = stringToNumber(input + 1, len - 1);
    x = x + (pow(10, len - 1) * (input[0] - '0'));
    return x;
}

int stringToNumber(char input[])
{
    int len = length(input);
    int x = stringToNumber(input, len);
    return x;
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
    return 0;
}
