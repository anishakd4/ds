#include <iostream>
#include <unordered_map>
using namespace std;

int maxDistance(int arr[], int n)
{
    unordered_map<int, int> m;

    int max_distance = 0;
    for (int i = 0; i < n; i++)
    {
        if (m.find(arr[i]) == m.end())
        {
            m[arr[i]] = i;
        }
        else
        {
            max_distance = max(max_distance, i - m[arr[i]]);
        }
    }

    return max_distance;
}

int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << maxDistance(arr, arr_size) << endl;
    return 0;
}