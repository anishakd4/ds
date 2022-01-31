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

void printSubsetsOfArray(int input[], int size, int output[], int len)
{
    if (size == 0)
    {
        for (int i = 0; i < len; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    int output1[len];
    for (int i = 0; i < len; i++)
    {
        output1[i] = output[i];
    }
    printSubsetsOfArray(input + 1, size - 1, output1, len);

    int output2[len + 1];
    for (int i = 0; i < len; i++)
    {
        output2[i] = output[i];
    }
    output2[len] = input[0];
    printSubsetsOfArray(input + 1, size - 1, output2, len + 1);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    int output[0];
    printSubsetsOfArray(input, length, output, 0);
    return 0;
}