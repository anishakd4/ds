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

/*
int i=10;

int *p1 = &i;
Means p1 is a pointer to a int

int* * p2 = &p1
Means p2 is a pointer to (int*) which is a pointer. So p2 is a double pointer
*/

void increment1(int **p)
{
    p = p + 1;
}

void increment2(int **p)
{
    *p = *p + 1;
}

void increment3(int **p)
{
    **p = **p + 1;
}

int main()
{
    int i = 10;
    int *p = &i;
    int **dp = &p;

    /*

            dp(900)                          p(890)                                 (490)   i=10
    _________________               ____________________                    _______________________
    |   890         |     ====>>    |       490         |       ====>>      |          10          |
    |_______________|               |___________________|                   |______________________|

    */

    cout << "&dp: " << &dp << endl;

    cout << "&p: " << &p << endl;
    cout << "dp: " << dp << endl;

    cout << "p: " << p << endl;
    cout << "*dp: " << *dp << endl;

    cout << "i: " << i << endl;
    cout << "*p: " << *p << endl;
    cout << "**dp: " << **dp << endl;

    return 0;
}