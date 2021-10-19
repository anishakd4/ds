#include <iostream>
#include <unordered_map>

using namespace std;

void printDuplicates(int arr[], int n)
{
    unordered_map<int, int> myMap;
    bool results = false;

    for (int i = 0; i < n; i++)
    {
        myMap[arr[i]]++;
    }

    unordered_map<int, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
    {
        if (it->second > 1)
        {
            results = true;
            cout << it->first << endl;
        }
    }
    if (results == false)
    {
        cout << "-1" << endl;
    }
}

int main()
{

    int arr[] = {12, 11, 40, 12, 5, 6, 5, 12, 11};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printDuplicates(arr, arr_size);

    return 0;
}