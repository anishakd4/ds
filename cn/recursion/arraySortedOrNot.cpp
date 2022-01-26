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
    return 0;
}