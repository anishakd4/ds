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

void printArray(int output[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
}

void printSubsetSumToKHelper(int input[], int size, int k, int output[], int len)
{
    if (k == 0)
    {
        printArray(output, len);
        return;
    }
    else if (k < 0)
    {
        return;
    }
    if (size == 0)
    {
        return;
    }

    int output1[len];
    for (int i = 0; i < len; i++)
    {
        output1[i] = output[i];
    }
    printSubsetSumToKHelper(input + 1, size - 1, k, output1, len);

    int output2[len + 1];
    for (int i = 0; i < len; i++)
    {
        output2[i] = output[i];
    }
    output2[len] = input[0];
    printSubsetSumToKHelper(input + 1, size - 1, k - input[0], output2, len + 1);
}

void printSubsetSumToK(int input[], int size, int k)
{
    int output[0];
    printSubsetSumToKHelper(input, size, k, output, 0);
}
int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    cin >> k;
    printSubsetSumToK(input, length, k);
    return 0;
}