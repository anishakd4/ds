/*
Given an input string (STR), print all possible permutations of the input string.

Note:
    The input string may contain the same characters, so there will also be the same permutations.
    The order of permutations doesn’t matter.

Input Format:
    The only input line contains a string (STR) of alphabets in lower case

Output Format:
    Print each permutations in a new line

Note:
    You do not need to print anything, it has already been taken care of. Just implement the function.

Constraint:
    1<=length of STR<=8

Time Limit: 1sec

Sample Input 1:
    cba

Sample Output 1:
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

void printPermutationsHelper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i <= output.size(); i++)
    {
        string temp = output;
        printPermutationsHelper(input.substr(1), temp.insert(i, 1, input[0]));
    }
}

void printPermutations(string input)
{
    printPermutationsHelper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}