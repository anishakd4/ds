#include <iostream>
#include <unordered_map>

using namespace std;

void smallestSubsegment(int arr[], int n)
{
    unordered_map<int, pair<int, int> > myHash;

    int res = 0;
    int max_freq = 0;
    int min_sublength = 1;
    for (int i = 0; i < n; i++)
    {
        if (myHash.find(arr[i]) != myHash.end())
        {
            myHash[arr[i]] = make_pair(myHash[arr[i]].first, myHash[arr[i]].second + 1);
            if (max_freq < myHash[arr[i]].second)
            {
                res = arr[i];
                max_freq = myHash[arr[i]].second;
                min_sublength = i - myHash[arr[i]].first;
            }
            else if (max_freq == myHash[arr[i]].second)
            {
                if (min_sublength > i - myHash[arr[i]].first)
                {
                    res = arr[i];
                    min_sublength = i - myHash[arr[i]].first;
                }
            }
        }
        else
        {
            myHash[arr[i]] = make_pair(i, 1);
        }
    }

    for (int i = myHash[res].first; i <= myHash[res].first + min_sublength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {4, 1, 1, 2, 2, 1, 3, 3};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    smallestSubsegment(arr, arr_size);

    return 0;
}