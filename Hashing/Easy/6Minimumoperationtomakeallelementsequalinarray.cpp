#include <iostream>
#include <unordered_map>
using namespace std;

int minOperation(int arr[], int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    int max_count = 0;
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        max_count = max(max_count, it->second);
    }

    return (n - max_count);
}

int main()
{
    int arr[] = {1, 5, 2, 1, 3, 2, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << minOperation(arr, arr_size) << endl;
    ;
    return 0;
}