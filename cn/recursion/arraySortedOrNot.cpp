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
    int arr[6] = {2, 3, 4, 5, 6, 1};
    if (is_sorted(arr, 6))
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }

    int brr[5] = {2, 3, 4, 5, 6};
    if (is_sorted2(brr, 5))
    {
        cout << "Array is sorted" << endl;
    }
    else
    {
        cout << "Array is not sorted" << endl;
    }
    return 0;
}