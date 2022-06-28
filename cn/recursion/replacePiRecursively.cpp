/*
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
    1 <= |S| <= 50
    where |S| represents the length of string S.

Sample Input 1 :
    xpix

Sample Output 1 :
    x3.14x

Sample Input 2 :
    pipi

Sample Output 2 :
    3.143.14

Sample Input 3 :
    pip

Sample Output 3 :
    3.14p

Constraints:-
    1<=|S|<=50
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