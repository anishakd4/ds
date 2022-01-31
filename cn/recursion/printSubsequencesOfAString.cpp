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

void printSubs(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    printSubs(input.substr(1), output);
    printSubs(input.substr(1), output + input[0]);
}

void printSubs(string input)
{
    printSubs(input, "");
}

int main()
{
    string input;
    cin >> input;
    printSubs(input);
    return 0;
}