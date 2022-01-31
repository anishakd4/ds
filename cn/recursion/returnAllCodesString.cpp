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

int getAllCodes(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string output1[10000];
    char c1 = (input[0] - 48) + 96;
    int size1 = getAllCodes(input.substr(1), output1);
    for (int i = 0; i < size1; i++)
    {
        output1[i] = c1 + output1[i];
    }

    int size2 = 0;
    string output2[10000];
    if (input.size() > 1)
    {
        int d = (input[0] - 48) * 10 + (input[1] - 48);
        if (d <= 26)
        {
            char c2 = 96 + d;
            size2 = getAllCodes(input.substr(2), output2);
            for (int i = 0; i < size2; i++)
            {
                output2[i] = c2 + output2[i];
            }
        }
    }
    for (int i = 0; i < size1; i++)
    {
        output[i] = output1[i];
    }
    for (int i = 0; i < size2; i++)
    {
        output[i + size1] = output2[i];
    }

    return (size1 + size2);
}

int main()
{
    string input;
    string output[10000];
    cin >> input;

    int count = getAllCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}