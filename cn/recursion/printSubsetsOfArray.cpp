/*
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important. Just print the subsets in different lines.

Input format :
    Line 1 : Integer n, Size of array
    Line 2 : Array elements (separated by space)

Constraints :
    1 <= n <= 15

Sample Input:
    3
    15 20 12

Sample Output:
    [] (this just represents an empty array, don't worry about the square brackets)
    12
    20
    20 12
    15
    15 12
    15 20
    15 20 12
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

void printSubsetsOfArray(int input[], int size, int output[], int len)
{
    if (size == 0)
    {
        for (int i = 0; i < len; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    int output1[len];
    for (int i = 0; i < len; i++)
    {
        output1[i] = output[i];
    }
    printSubsetsOfArray(input + 1, size - 1, output1, len);

    int output2[len + 1];
    for (int i = 0; i < len; i++)
    {
        output2[i] = output[i];
    }
    output2[len] = input[0];
    printSubsetsOfArray(input + 1, size - 1, output2, len + 1);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    int output[0];
    printSubsetsOfArray(input, length, output, 0);
    return 0;
}