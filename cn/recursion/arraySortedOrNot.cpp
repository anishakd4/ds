/*
Check if given array is sorted or not recursively.

Input Format :
    Line 1 : An Integer N i.e. size of array
    Line 2 : N integers which are elements of the array, separated by spaces

Output Format :
    Print "Array is sorted" if array is sorted else "Array is not sorted

Constraints :
    1 <= N <= 10^3

Sample Input 1:
    2 3 6 8 10

Sample Output 1:
    Array is sorted

Sample Input 2:
    2 3 6 8 5 10

Sample Output 2:
    Array is not sorted

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

// Here we first check rest of the array and then perform our check
bool is_sorted2(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }

    bool isSmallerOutput = is_sorted2(arr + 1, size - 1);
    if (!isSmallerOutput)
    {
        return false;
    }

    if (arr[0] > arr[1])
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Here we first perform our check and then check rest of the array
bool is_sorted(int arr[], int size)
{
    if (size == 0 || size == 1)
    {
        return true;
    }
    if (arr[0] > arr[1])
    {
        return false;
    }
    return is_sorted(arr + 1, size - 1);
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

    if (is_sorted(input, n))
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }

    return 0;
}