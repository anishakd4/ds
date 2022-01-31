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

void printPermutationsHelper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i <= output.size(); i++)
    {
        string temp = output;
        printPermutationsHelper(input.substr(1), temp.insert(i, 1, input[0]));
    }
}

void printPermutations(string input)
{
    printPermutationsHelper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}