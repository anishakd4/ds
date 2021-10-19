#include <iostream>

using namespace std;

void printFrequency(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] = arr[arr[i] % n] + n;
    }

    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << " : " << (arr[i] / n) << endl;
    }
}

int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printFrequency(arr, arr_size);

    return 0;
}