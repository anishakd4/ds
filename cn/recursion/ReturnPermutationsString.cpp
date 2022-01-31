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

int returnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }

    string smallOutput[1000];
    int count = returnPermutations(input.substr(1), smallOutput);

    string temp;
    int k = 0;
    for (int i = 0; i < count; i++)
    {
        temp = smallOutput[i];
        for (int j = 0; j <= temp.length(); j++)
        {
            temp.insert(j, 1, input[0]);
            output[k] = temp;
            temp = smallOutput[i];
            k++;
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}