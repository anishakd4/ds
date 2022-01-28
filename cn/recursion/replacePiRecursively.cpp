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

void replacePi(char input[])
{
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }

    replacePi(input + 1);

    if (input[0] == 'p' && input[1] == 'i')
    {
        int length = 0;
        while (input[length] != '\0')
        {
            length++;
        }
        for (int i = length; i >= 2; i--)
        {
            input[i + 2] = input[i];
        }
        length = length + 2;

        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
    return 0;
}