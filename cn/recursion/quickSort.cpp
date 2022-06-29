/*
Sort an array A using Quick Sort. Change in the input array itself. So no need to return or print anything.

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
    1 5 2 7 3

Sample Output 2 :
    1 2 3 5 7
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
    delete[] input;
    return 0;
}