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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int input[], int low, int high)
{
    int pivot = input[high];
    int i = low;
    for (int j = low; j <= high; j++)
    {
        if (input[j] < pivot)
        {
            swap(&input[i], &input[j]);
            i++;
        }
    }
    swap(&input[i], &input[high]);
    return (i);
}

void quickSort(int input[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int pi = partition(input, low, high);
    quickSort(input, low, pi - 1);
    quickSort(input, pi + 1, high);
}

void quicksort(int input[], int size)
{
    quickSort(input, 0, size - 1);
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
    quicksort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;
    return 0;
}