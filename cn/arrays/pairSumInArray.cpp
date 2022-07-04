/*
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
    Given array/list can contain duplicate elements.

Input format :
    The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
    First line of each test case or query contains an integer 'N' representing the size of the first array/list.
    Second line contains 'N' single space separated integers representing the elements in the array/list.
    Third line contains an integer 'num'.

Output format :
    For each test case, print the total number of pairs present in the array/list.
    Output for every test case will be printed in a separate line.

Constraints :
    1 <= t <= 10^2
    0 <= N <= 10^4
    0 <= num <= 10^9

Time Limit: 1 sec

Sample Input 1:
    1
    9
    1 3 6 2 5 4 3 2 4
    7

Sample Output 1:
    7

Sample Input 2:
    2
    9
    1 3 6 2 5 4 3 2 4
    12
    6
    2 8 10 5 -2 5
    10

Sample Output 2:
    0
    2

Explanation for Input 2:
    Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.
    For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
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

int pairSum(int *arr, int n, int num)
{
    int ans = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < n; i++)
    {
        if (umap.find(arr[i]) != umap.end())
        {
            umap[arr[i]] = umap[arr[i]] + 1;
        }
        else
        {
            umap[arr[i]] = 1;
        }
    }

    for (auto &it : umap)
    {
        if (num - it.first != it.first)
        {
            if (umap.find(num - (it.first)) != umap.end())
            {
                ans = ans + (umap[num - (it.first)] * it.second);
            }
        }
        else
        {
            if (it.second > 1)
            {
                ans = ans + (((it.second - 1) * (it.second)) / 2);
            }
        }
        umap[it.first] = 0;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t > 0)
    {
        int size;
        int x;

        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cin >> x;

        cout << pairSum(input, size, x) << endl;

        delete[] input;
        t--;
    }
    return 0;
}
