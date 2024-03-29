/*
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important.

Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Input Format :
    String S

Output Format :
    All permutations (in different lines)

Sample Input :
    abc

Sample Output :
    abc
    acb
    bac
    bca
    cab
    cba
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

int returnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int count = returnPermutations(input.substr(1), smallOutput);

    string temp;
    int k = 0;
    for (int i = 0; i < count; i++)
    {
        temp = smallOutput[i];
        for (int j = 0; j <= temp.length(); j++)
        {
            temp.insert(j, 1, input[0]);
            output[k] = temp;
            temp = smallOutput[i];
            k++;
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}