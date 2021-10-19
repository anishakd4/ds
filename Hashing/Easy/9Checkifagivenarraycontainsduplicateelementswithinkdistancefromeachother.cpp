#include <iostream>
#include <unordered_map>

using namespace std;

bool checkDuplicatesWithinK(int arr[], int n, int k)
{
    unordered_map<int, int> myset;

    for (int i = 0; i < n; i++)
    {
        if (myset.find(arr[i]) != myset.end())
        {
            if (i - myset[arr[i]] <= k)
            {
                return true;
            }
            myset[arr[i]] = i;
        }
        else
        {
            myset[arr[i]] = i;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 4};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    if (checkDuplicatesWithinK(arr, arr_size, 3))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}