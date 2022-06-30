/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.

Note : The order of subsets are not important.

Input format :
    Line 1 : Integer n, Size of input array
    Line 2 : Array elements separated by space
    Line 3 : K

Constraints :
    1 <= n <= 20

Sample Input :
    9
    5 12 3 17 1 18 15 3 17
    6

Sample Output :
    3 3
    5 1
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

int subsetSumToK(int arr[], int n, int output[][50], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            output[0][0] = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (k == 0)
    {
        output[0][0] = 0;
        return 1;
    }
    else if (k < 0)
    {
        return 0;
    }

    int output1[1000][50];
    int size1 = subsetSumToK(arr + 1, n - 1, output1, k - arr[0]);

    int output2[1000][50];
    int size2 = subsetSumToK(arr + 1, n - 1, output2, k);

    int i, j;

    for (i = 0; i < size1; i++)
    {
        output[i][0] = output1[i][0] + 1;
        output[i][1] = arr[0];
    }

    for (i = 0; i < size1; i++)
    {
        for (j = 1; j <= output1[i][0]; j++)
        {
            output[i][j + 1] = output1[i][j];
        }
    }

    for (i = 0; i < size2; i++)
    {
        for (j = 0; j <= output2[i][0]; j++)
        {
            output[i + size1][j] = output2[i][j];
        }
    }

    return size1 + size2;
}

int main()
{
    int input[20], length, output[10000][50], k;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }

    cin >> k;

    int size = subsetSumToK(input, length, output, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= output[i][0]; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}