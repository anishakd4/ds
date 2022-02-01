#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <climits>
#include <sys/time.h>
// climits for INT_MIN
#include <unordered_map>
using namespace std;

long timeInMicroseconds()
{
    struct timeval start;
    gettimeofday(&start, NULL);
    return (start.tv_sec * 1000000 + start.tv_usec);
}

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
    for (int n = 10; n <= 1000000; n *= 10)
    {
        int *arr = new int[n];
        long startTime, endTime;
        for (int i = 0; i < n; i++)
        {
            arr[i] = n - i;
        }
        startTime = timeInMicroseconds();
        mergeSort(arr, 0, n - 1);
        endTime = timeInMicroseconds();
        cout << "Merge sort for n = " << n << " size time= " << (endTime - startTime) << endl;
    }
    return 0;
}