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

void selectionSort(int arr[], int n)
{
    for (int j = 0; j < n - 1; j++)
    {
        int min = arr[j];
        int pos = j;
        for (int i = j + 1; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                pos = i;
            }
            int temp = arr[j];
            arr[j] = min;
            arr[pos] = temp;
        }
    }
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
        selectionSort(arr, n);
        endTime = timeInMicroseconds();
        cout << "Merge sort for n = " << n << " size time= " << (endTime - startTime) << endl;
    }
    return 0;
}