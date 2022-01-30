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