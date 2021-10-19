#include <iostream>

using namespace std;

void findCounts(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] <= 0)
        {
            i++;
            continue;
        }
        int elementIndex = arr[i] - 1;

        if (arr[elementIndex] > 0)
        {
            arr[i] = arr[elementIndex];
            arr[elementIndex] = -1;
        }
        else
        {
            arr[elementIndex]--;
            arr[i] = 0;
            i++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << ":" << abs(arr[i]) << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {2, 3, 3, 2, 5};
    findCounts(arr, sizeof(arr) / sizeof(arr[0]));

    int arr2[] = {1, 3, 5, 7, 9, 1, 3, 5, 7, 9, 1};
    findCounts(arr2, sizeof(arr2) / sizeof(arr2[0]));
    return 0;
}