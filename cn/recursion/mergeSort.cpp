/*
Sort an array A using Merge Sort. Change in the input array itself

Input format :
    Line 1 : Integer n i.e. Array size
    Line 2 : Array elements (separated by space)

Output format :
    Array elements in increasing order (separated by space)

Constraints :
    1 <= n <= 10^3

Sample Input 1 :
    6
    2 6 8 5 4 3

Sample Output 1 :
    2 3 4 5 6 8

Sample Input 2 :
    5
    2 1 5 2 3

Sample Output 2 :
    1 2 2 3 5
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

void merge(int arr[], int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
int main()
{
    int length;
    cin >> length;
    int *arr = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, length - 1);
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}