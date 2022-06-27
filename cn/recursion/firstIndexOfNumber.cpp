/*
First Index of Number

Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present
in the array. First index means, the index of first occurrence of x in the input array. Do this recursively. Indexing in the array starts from 0.


Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces
    Line 3 : Integer x

Output Format :
    first index or -1

Constraints :
    1 <= N <= 10^3

Sample Input :
    4
    9 8 10 8
    8

Sample Output :
    1
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

int firstIndex(int input[], int size, int x)
{
    if (input[0] == x)
    {
        return 0;
    }

    if (size == 1)
    {
        return -1;
    }
    else
    {
        int an = firstIndex(input + 1, size - 1, x);
        if (an >= 0)
        {
            return an + 1;
        }
        else
        {
            return an;
        }
    }
}
int main()
{
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int x;

    cin >> x;

    cout << firstIndex(input, n, x) << endl;

    return 0;
}