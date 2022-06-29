/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.

Note : The order of strings are not important. Just print different strings in new lines.

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

void printKeypad(int num, string out)
{
    if (num == 0)
    {
        cout << out << endl;
        return;
    }
    string str = dial(num % 10);
    for (int i = 0; i < str.size(); i++)
    {
        printKeypad(num / 10, str[i] + out);
    }
}

void printKeypad(int num)
{
    printKeypad(num, "");
}

int main()
{
    int num;
    cin >> num;
    printKeypad(num);
    return 0;
}