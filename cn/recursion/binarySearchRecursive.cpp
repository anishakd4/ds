/*
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x. Return
-1 if x is not present in the given array.

Note : If given array size is even, take first mid.

Input format :
    Line 1 : Array size
    Line 2 : Array elements (separated by space)
    Line 3 : x (element to be searched)

Sample Input :
    6
    2 3 4 5 6 8
    5

Sample Output:
    3
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

int binarySearch(int input[], int start, int end, int element)
{
    if (start > end)
    {
        return -1;
    }
    int mid = (start + end) / 2;
    if (input[mid] == element)
    {
        return mid;
    }
    else if (input[mid] > element)
    {
        return binarySearch(input, start, mid - 1, element);
    }
    else
    {
        return binarySearch(input, mid + 1, end, element);
    }
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    cin >> element;
    ans = binarySearch(input, 0, length - 1, element);
    cout << ans << endl;
    return 0;
}