#include <iostream>
#include <unordered_map>
using namespace std;

int mostFrequent(int arr[], int n)
{
    unordered_map<int, int> myHash;

    for (int i = 0; i < n; i++)
    {
        myHash[arr[i]]++;
    }

    int max_count = 0;
    int res = -1;

    unordered_map<int, int>::iterator it;
    for (it = myHash.begin(); it != myHash.end(); it++)
    {
        if (max_count < it->second)
        {
            max_count = it->second;
            res = it->first;
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 5, 2, 1, 3, 2, 1};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    cout << mostFrequent(arr, arr_size) << endl;
    return 0;
}